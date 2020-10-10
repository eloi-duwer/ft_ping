/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   await_pongs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:12:35 by eduwer            #+#    #+#             */
/*   Updated: 2020/10/11 00:50:26 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ping.h>

void	fill_msghdr(struct msghdr *message, struct iovec *io, \
	t_echo_req *response, void *control_buffer, size_t ctrl_len)
{
	bzero(io, sizeof(struct iovec));
	bzero(message, sizeof(struct msghdr));
	bzero(response, sizeof(t_echo_req));
	bzero(control_buffer, ctrl_len);
	io->iov_base = response;
	io->iov_len = sizeof(t_echo_req);
	message->msg_name = NULL;
	message->msg_namelen = 0;
	message->msg_iov = io;
	message->msg_iovlen = 1;
	message->msg_control = control_buffer;
	message->msg_controllen = ctrl_len;
	message->msg_flags = 0;
}

static char	*get_icmp_response(int type)
{
	if (type == ICMP_ECHOREPLY)
		return ("Echo Reply");
	else if (type == ICMP_DEST_UNREACH)
		return("Destination Unreachable");
	else if (type == ICMP_SOURCE_QUENCH)
		return("Source Quench");
	else if (type == ICMP_REDIRECT)
		return ("Redirect (change route)");
	else if (type == ICMP_ECHO)
		return ("Echo Request");
	else if (type == ICMP_TIME_EXCEEDED)
		return ("Time to live Exceeded");
	else if (type == ICMP_PARAMETERPROB)
		return ("Parameter Problem");
	else if (type == ICMP_TIMESTAMP)
		return 	("Timestamp Request");
	else if (type == ICMP_TIMESTAMPREPLY)
		return ("Timestamp Reply");
	else if (type == ICMP_INFO_REQUEST)
		return ("Information Request");
	else if (type == ICMP_INFO_REPLY)
		return 	("Information Reply");
	else if (type == ICMP_ADDRESS)
		return 	("Address Mask Request");
	else if (type == ICMP_ADDRESSREPLY)
		return ("Address Mask Reply");
	else
		return (NULL);
}

static void	handle_icmp_types(t_echo_req *res)
{
	char	sender[100];

	if (inet_ntop(AF_INET, &res->ip_header.saddr, sender, 99) == NULL)
		perror_and_exit("Error during inet_ntop");

	printf("From %s (%s) icmp_seq=%hd %s\n", \
		get_domain(res->ip_header.saddr), sender, \
		ntohs(res->icmp_header.un.echo.sequence), \
		get_icmp_response(res->icmp_header.type));
}

static void	print_and_update_infos(t_echo_req *res)
{
	char			sender[100];
	struct timeval	*precedent;
	struct timeval	current;
	double			difftime;

	if (g_infos.verbose == true)
	{
		printf("Recieved echo reply:\n");
		print_packet(res);
	}
	precedent = (struct timeval *)res->payload;
	gettimeofday(&current, NULL);
	difftime = get_ms(&current) - get_ms(precedent);
	if (inet_ntop(AF_INET, &res->ip_header.saddr, sender, 99) == NULL)
		perror_and_exit("Error during inet_ntop");
	printf("%ld bytes from %s (%s): icmp_seq=%hd ttl=%hd time=%.1f ms\n", \
		ntohs(res->ip_header.tot_len) - sizeof(struct iphdr), get_domain(res->ip_header.saddr), sender, \
		ntohs(res->icmp_header.un.echo.sequence), res->ip_header.ttl, difftime);
	g_infos.stats.nb_received++;
	if (g_infos.stats.rtt_max == 0.0f || g_infos.stats.rtt_max < difftime)
		g_infos.stats.rtt_max = difftime;
	if (g_infos.stats.rtt_min == 0.0f || g_infos.stats.rtt_min > difftime)
		g_infos.stats.rtt_min = difftime;
	g_infos.stats.rtt_tot += difftime;
	g_infos.stats.rtt_squared += difftime * difftime;
}

void		await_pongs()
{
		char			control_buffer[512];
		int				ret;
		t_echo_req		response;
		struct iovec	io;
		struct msghdr	message;

	while (true) {
		fill_msghdr(&message, &io, &response, control_buffer, 512);
		ret = recvmsg(g_infos.sockfd, &message, 0);
		if (ret == -1)
		{
			if (errno != EAGAIN && errno != EWOULDBLOCK && errno != EINTR)
				perror_and_exit("Error during recvmsg");
		}
		else if (response.icmp_header.type != ICMP_ECHOREPLY)
		{
			if (g_infos.verbose == true)
			{
				printf("Recieved a packet that is not an echo reply:\n");
				print_packet(&response);
			}
			if (response.icmp_header.type != ICMP_ECHO)
				handle_icmp_types(&response);
		}
		else
			print_and_update_infos(&response);
	}
}
