/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:34:20 by eduwer            #+#    #+#             */
/*   Updated: 2020/10/11 13:19:09 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ping.h>

t_infos	g_infos =
{
	.seq = 0,
	.verbose = false,
	.ttl = 64,
	.addr_name = NULL,
	.timeout = 10,
	.no_dns = false,
	.print_timestamps = false,
	.stop_count = 0,
	.ping_interval = 1000
};

void	get_address(char *str)
{
	struct addrinfo hints;
	struct addrinfo *ret;

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;
	hints.ai_flags = AI_CANONNAME;
	if (getaddrinfo(str, NULL, &hints, &ret) != 0)
		perror_and_exit("Cannot convert address to ip");
	g_infos.addr.sin_addr.s_addr = ((struct sockaddr_in *)ret->ai_addr)->sin_addr.s_addr;
	g_infos.addr_name = str;
	freeaddrinfo(ret);
}

void	parse_args(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (ft_strcmp(av[i], "-h") == 0)
				print_help();
			else if (ft_strcmp(av[i], "-v") == 0)
				g_infos.verbose = true;
			else if (ft_strcmp(av[i], "-n") == 0)
				g_infos.no_dns = true;
			else if (ft_strcmp(av[i], "-D") == 0)
				g_infos.print_timestamps = true;
			else if (ft_strcmp(av[i], "-t") == 0)
			{
				if (i == ac - 1)
				{
					printf("ttl needs an integer between 1 and 255\n");
					exit(1);
				}
				g_infos.ttl = atoi(av[i + 1]);
				if (g_infos.ttl <= 0 || g_infos.ttl > 255)
				{
					printf("ttl must be an integer between 1 and 255\n");
					exit(1);
				}
				i++;
			}
			else if (ft_strcmp(av[i], "-W") == 0)
			{
				if (i == ac - 1)
				{
					printf("timeout needs a positive integer\n");
					exit(1);
				}
				g_infos.timeout = (unsigned int)atoi(av[i + 1]);
				i++;
			}
			else if (ft_strcmp(av[i], "-c") == 0)
			{
				if (i == ac - 1)
				{
					printf("Count needs an integer\n");
					exit(1);
				}
				g_infos.stop_count = atoi(av[i + 1]);
				i++;
			}
			else if (ft_strcmp(av[i], "-i") == 0)
			{
				if (i == ac - 1)
				{
					printf("Interval needs an integer\n");
					exit(1);
				}
				g_infos.ping_interval = (unsigned int)atoi(av[i + 1]);
				i++;
			}
			else
			{
				printf("Unrecognized option: %s\n", av[i]);
				exit(1);
			}
			
		}
		else if (g_infos.addr_name == NULL)
			get_address(av[i]);
		else
			print_help();
		i++;
	}
}

void	create_socket()
{
	struct timeval	timeout;		

	timeout.tv_sec = g_infos.timeout;
	timeout.tv_usec = 0;
	g_infos.sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (g_infos.sockfd == -1)
		perror_and_exit("Cannot open socket");
	if (setsockopt(g_infos.sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1
		|| setsockopt(g_infos.sockfd, IPPROTO_IP, IP_HDRINCL, (int[1]){1}, sizeof(int)) == -1)
	{
		perror_and_exit("Error while setting socket options");
	}
}

static void	exit_prog(int signb)
{
	struct timeval	current;
	double			mean;
	double			std_dev;

	(void)signb;
	close(g_infos.sockfd);
	printf("\n--- %s ping statistics ---\n", g_infos.addr_name);
	printf("%d packets transmitted, %d received, ", g_infos.seq, g_infos.stats.nb_received);
	if (g_infos.seq != g_infos.stats.nb_received)
		printf("+%d errors, ", g_infos.seq - g_infos.stats.nb_received);
	gettimeofday(&current, NULL);
	printf("%.f%% packet loss, time %.fms\n",  (double)(g_infos.seq - g_infos.stats.nb_received) / (double)g_infos.seq * 100.0f, \
		get_ms(&current) - get_ms(&g_infos.stats.start_time));
	if (g_infos.stats.nb_received != 0)
	{
		mean = (double)g_infos.stats.rtt_tot / (double)g_infos.stats.nb_received;
		g_infos.stats.rtt_squared /= g_infos.stats.nb_received;
		std_dev = sqrt(g_infos.stats.rtt_squared - mean * mean);
		printf("rtt min/max/avg/mdev = %.3f/%.3f/%.3f/%.3f ms\n", g_infos.stats.rtt_min, \
			g_infos.stats.rtt_max, mean, std_dev);
	}
	exit(0);
}

static void	init_stats()
{
	g_infos.stats.rtt_max = 0.0f;
	g_infos.stats.rtt_min = 0.0f;
	g_infos.stats.rtt_tot = 0;
	g_infos.stats.rtt_squared = 0;
	g_infos.stats.nb_received = 0;
	if (gettimeofday(&g_infos.stats.start_time, NULL) == -1)
		perror("Error during gettimeofday");
}

void	print_start_ping(void)
{
	char	dest[100];

	if (inet_ntop(AF_INET, &g_infos.addr.sin_addr.s_addr, dest, 99) == NULL)
		perror_and_exit("Error during inet_ntop");
	printf("PING %s (%s) %d(%ld) bytes of data.\n", g_infos.addr_name, dest, PAYLOAD_SIZE, sizeof(t_echo_req));
}

void	start_timer()
{
	struct itimerval	timer;

	timer.it_value.tv_sec = g_infos.ping_interval / 1000;
	timer.it_value.tv_usec = (g_infos.ping_interval * 1000) % 1000000;
	ft_memcpy(&timer.it_interval, &timer.it_value, sizeof(struct timeval));
	if (setitimer(ITIMER_REAL, &timer, NULL) == -1)
		perror_and_exit("Error during setitimer");
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		print_help();
	signal(SIGALRM, &send_ping);
	signal(SIGINT, &exit_prog);
	parse_args(argc, argv);
	create_socket();
	init_stats();
	print_start_ping();
	start_timer();
	send_ping(0);
	await_pongs();
	return (0);
}
