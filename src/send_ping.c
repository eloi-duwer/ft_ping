/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:01:00 by eduwer            #+#    #+#             */
/*   Updated: 2020/10/11 00:39:46 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ping.h>

static unsigned short	checksum_icmphdr(void *data, size_t size)
{
	unsigned long	sum;
	unsigned short	*ptr;

	sum = 0;
	ptr = (unsigned short *)data;
	while (size > 1)
	{
		sum += (((*ptr & 0xff00) >> 8) +
			((*ptr & 0xff) << 8));
		size -= sizeof(unsigned short);
		ptr++;
	}
	sum = ~((sum & 0xffff) + ((sum & 0xffff0000) >> 16));
	return ((unsigned short)sum);
}

static void				fill_ip_header(t_echo_req *req)
{
	req->ip_header.version = 4;
	req->ip_header.ihl = 5;
	req->ip_header.tos = 0;
	req->ip_header.tot_len = htons(sizeof(t_echo_req));
	req->ip_header.id = 0;
	req->ip_header.frag_off = 0;
	req->ip_header.ttl = g_infos.ttl;
	req->ip_header.protocol = IPPROTO_ICMP;
	req->ip_header.check = 0;
	req->ip_header.saddr = INADDR_ANY;
	req->ip_header.daddr = g_infos.addr.sin_addr.s_addr;
}

static void				fill_icmp_header(t_echo_req *req)
{
	req->icmp_header.type = ICMP_ECHO;
	req->icmp_header.code = 0;
	req->icmp_header.un.echo.id = htons(getpid());
	req->icmp_header.un.echo.sequence = htons(g_infos.seq);
	memset(&req->payload, 0, sizeof(char) * PAYLOAD_SIZE);
	if (gettimeofday((void *)&req->payload, NULL) == -1)
		perror_and_exit("Error during gettimeofday");
	req->icmp_header.checksum = 0;
	req->icmp_header.checksum = htons(checksum_icmphdr(&req->icmp_header, sizeof(t_echo_req) - offsetof(t_echo_req, icmp_header)));
}

void					send_ping(int signb)
{
	t_echo_req	req;
	int			ret;

	(void)signb;
	g_infos.seq++;
	memset(&req, 0, sizeof(t_echo_req));
	fill_ip_header(&req);
	fill_icmp_header(&req);
	ret = sendto(g_infos.sockfd, &req, sizeof(t_echo_req), 0, (struct sockaddr *)&g_infos.addr, sizeof(struct sockaddr));
	if (ret == -1)
		perror("Error while sending packet");
	if (g_infos.verbose == true)
	{
		printf("Sent request, %d bytes\n", ret);
		print_packet(&req);
	}
	alarm(1);
}
