/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:31:52 by eduwer            #+#    #+#             */
/*   Updated: 2020/07/10 17:40:41 by eduwer           ###   ########.fr       */
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
# include <signal.h>
//En attendant la libft
# include <string.h>
# define REQ_SIZE 64
# define ECHO_REQ 8
# define ECHO_RES 0
# define TIMEOUT_REQ 5

typedef enum 		e_bool {
	false,
	true
}					t_bool;

typedef	struct		s_infos {
	unsigned short	seq;
	t_bool			timeout;
	
}					t_infos;

extern t_infos		g_infos;

typedef struct		s_icmp_header {
	unsigned char	type;
	unsigned char	code;
	unsigned short	checksum;
	unsigned short	id;
	unsigned short	seq;
}					t_icmp_header;

typedef struct		s_echo_req {
	t_icmp_header	header;
	struct timeval	time;
	char			data[REQ_SIZE];
}					t_echo_req;

#endif

