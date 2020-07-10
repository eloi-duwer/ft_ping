/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:34:20 by eduwer            #+#    #+#             */
/*   Updated: 2020/07/10 17:41:47 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ping.h>

t_infos	g_infos =
{
	.seq = 0,
	.timeout = false
};

void	print_help(void)
{
	printf("Usage: ft_ping [options] <destination>\n\nOptions:\n  \
<destination>\tdns name or op address\n  -v\tverbose output\n  \
-h\tprint help and exit\n");
	exit(0);
}

void	setSockOptions(int sockfd)
{
	int				ttl;
	struct timeval	timeout;
	
	ttl = 128;
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;
	if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) == -1 \
	 || setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, \
	 	&timeout, sizeof(timeout)) == -1)
	{
		printf("Error while setting socket options\n");
		exit(1);
	}
}

unsigned short	checksum(t_echo_req *req)
{
	unsigned short		res;
	unsigned short		*ptr;
	long unsigned int	i;

	res = 0;
	i = 0;
	ptr = (unsigned short *)req;
	while (i < sizeof(t_echo_req) / 2)
	{
		res += ptr[i];
		++i;
	}
	return (~res);
}

void			send_ping(int sockfd, struct addrinfo *addr)
{
	t_echo_req		req;
	int				size;
	int				ret;

	req.header.type = ECHO_REQ;
	req.header.code = 0;
	req.header.checksum = 0;
	req.header.id = 0;
	req.header.seq = g_infos.seq++;
	memset(req.data, ' ', REQ_SIZE);
	gettimeofday(&req.time, NULL);
	req.header.checksum = checksum(&req);
	size = sendto(sockfd, (void *)&req, sizeof(req), 0, addr->ai_addr, \
		sizeof(*(addr->ai_addr)));
	printf("sent %d bytes of data\n", size);
	alarm(TIMEOUT_REQ);
	while (g_infos.timeout == false)
	{
		ret = recvmsg()
		
	}
}

static void		alarm_handler(int nb)
{
	(void)nb;
	g_infos.timeout = true;
}

int				main(int argc, char **argv)
{
	struct addrinfo hint;
	struct addrinfo	*addr;
	char	str[255];
	void	*ptrr;
	int		sockfd;

	if (argc == 1)
		print_help();
	signal(SIGALRM, &alarm_handler);
	hint.ai_family = AF_INET;
	hint.ai_socktype = SOCK_RAW;
	hint.ai_protocol = IPPROTO_ICMP;
	hint.ai_flags = AI_CANONNAME;
	getaddrinfo(argv[1], NULL, &hint, &addr);
	inet_ntop(addr->ai_family, addr->ai_addr->sa_data, str, 255);
	switch (addr->ai_family)
	{
		case AF_INET:
			ptrr = &((struct sockaddr_in *) addr->ai_addr)->sin_addr;
			break;
		case AF_INET6:
			ptrr = &((struct sockaddr_in6 *) addr->ai_addr)->sin6_addr;
			break;
	}
	inet_ntop (addr->ai_family, ptrr, str, 255);
	printf ("IPv%d address: %s (%s)\n", addr->ai_family == PF_INET6 ? 6 : 4,
		str, addr->ai_canonname);
	if ((sockfd = socket(AF_INET, SOCK_RAW | SOCK_CLOEXEC | SOCK_NONBLOCK, IPPROTO_ICMP)) == -1)
	{
		printf("Can't open socket\n");
		exit(1);
	}
	setSockOptions(sockfd);
	send_ping(sockfd, addr);
	
}
