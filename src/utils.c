/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 23:17:50 by eduwer            #+#    #+#             */
/*   Updated: 2020/10/11 13:05:28 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ping.h>

void	print_help(void)
{
	printf("Usage: ft_ping [options] <destination>\n\nOptions:\
\n  <destination>\tdomain name or ip v4 address\
\n  -c <count>\tstop after <count> replies (negative or 0 for infinite)\
\n	-D\t\tprint timestamps\
\n  -h\t\tprint this help and exit\
\n  -i <interval>\tinterval between sending each packet (in ms) (default 1000)\
\n  -m\t\tno dns resolution\
\n  -t <number>\tset ttl (must be between 1 and 255)\
\n  -v\t\tverbose output\
\n  -W <number>\tset request timeout\
\n");
	exit(0);
}

void	perror_and_exit(char *str)
{
	perror("ft_ping");
	printf("%s\n", str);
	exit(1);
}

double	get_ms(struct timeval *time)
{
	return (((double)time->tv_sec * 1000.0f) + \
		((double)time->tv_usec / 1000.0f));
}

void	print_packet(t_echo_req *packet)
{
	char	address[100];

	printf("+--- IP header -----------------+\n");
	printf("|ver|ihl|  tos  |packet tot len |\n");
	printf("| %-2d| %-2d|  %-5d|     %-10d|\n", packet->ip_header.version, \
		packet->ip_header.ihl, packet->ip_header.tos, ntohs(packet->ip_header.tot_len));
	printf("+---------------+---------------+\n");
	printf("|identification |fragment offset|\n");
	printf("|     %-10d|     %-10d|\n", ntohs(packet->ip_header.id), ntohs(packet->ip_header.frag_off));
	printf("+---------------+---------------+\n");
	printf("|  ttl  |protoc.|   checksum    |\n");
	printf("|  %-5d|   %-4d|     %-10x|\n", packet->ip_header.ttl, packet->ip_header.protocol, ntohs(packet->ip_header.check));
	printf("+-------------------------------+\n");
	printf("|        source address         |\n");
	if (inet_ntop(AF_INET, &packet->ip_header.saddr, address, 99) == NULL)
		perror_and_exit("Error during inet_ntop");
	printf("|        %-23s|\n", address);
	printf("+-------------------------------+\n");
	printf("|      destination address      |\n");
	if (inet_ntop(AF_INET, &packet->ip_header.daddr, address, 99) == NULL)
		perror_and_exit("Error during inet_ntop");
	printf("|        %-23s|\n", address);
	printf("+--- ICMP header ---------------+\n");
	printf("|msg typ| code  |   checksum    |\n");
	printf("|  %-5d|  %-5d|     %-10x|\n", packet->icmp_header.type, packet->icmp_header.code, ntohs(packet->icmp_header.checksum));
	printf("+---------------+---------------+\n");
	printf("|   identifier  |sequence number|\n");
	printf("|   %-12d|     %-10d|\n", ntohs(packet->icmp_header.un.echo.id), ntohs(packet->icmp_header.un.echo.sequence));
	printf("+-------------------------------+\n\n");
}

char	*get_domain(uint32_t ip)
{
	static char			host[255] = {'\0'};
	struct sockaddr_in	addr;
	int					ret;

	addr.sin_addr.s_addr = ip;
	addr.sin_family = AF_INET;
	if ((ret = getnameinfo((struct sockaddr *)&addr, sizeof(struct sockaddr_in), host, 255, NULL, 0, 0)) != 0)
	{
		printf("Could not retrieve domain: %s\n", gai_strerror(ret));
		return (NULL);
	}
	else
		return (host);

}
