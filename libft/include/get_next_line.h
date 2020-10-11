/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:10:37 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 20:06:02 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 200

int		get_next_line(const int fd, char **line);
int		remalloc_the_line(char **line, int size);
int		size_to_add(char *line);
int		ft_empty_the_buffer(char **line, char **pt_buff, int i);
int		ft_check(int ret, char **line);

#endif
