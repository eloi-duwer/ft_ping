/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:31:52 by eduwer            #+#    #+#             */
/*   Updated: 2020/10/11 13:16:45 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PING_H__
# define __FT_PING_H__
# include <arpa/inet.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <unistd.h>
# include <netdb.h>
# include <netinet/ip_icmp.h>
# include <signal.h>
# include <errno.h>
# include <stdbool.h>
# include <stddef.h>
# include <float.h>
# include <math.h>
# include <libft.h>

# define PAYLOAD_SIZE 56

typedef struct		s_stats {
	int				nb_received;
	double			rtt_min;
	double			rtt_max;
	double			rtt_tot;
	double			rtt_squared;
	struct timeval	start_time;
}					t_stats;

typedef	struct		s_infos {
	unsigned short		seq;
	bool				verbose;
	bool				no_dns;
	bool				print_timestamps;
	unsigned int		timeout;
	unsigned int		ping_interval;
	int					stop_count;
	int					ttl;
	int					sockfd;
	struct sockaddr_in	addr;
	char				*addr_name;
	t_stats				stats;
}					t_infos;

extern t_infos		g_infos;

typedef struct		s_echo_req {
	struct iphdr	ip_header;
	struct icmphdr	icmp_header;
	char			payload[PAYLOAD_SIZE];
}					t_echo_req;

void	send_ping(int signb);
void	await_pongs(void);
void	perror_and_exit(char *str);
double	get_ms(struct timeval *time);
void	print_help(void);
void	print_packet(t_echo_req *packet);
char	*get_domain(uint32_t ip);

#endif

