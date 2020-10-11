/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:49:01 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:30:29 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int				remalloc_the_line(char **line, int size)
{
	char *buff;

	size = ft_strlen(*line) + size + 1;
	if ((buff = (char *)malloc(size)) == NULL)
		return (-1);
	ft_memset(buff, 0, size);
	ft_strcpy(buff, *line);
	free(*line);
	*line = buff;
	return (0);
}

int				size_to_add(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	return (i);
}

int				ft_empty_the_buffer(char **line, char **pt_buff, int i)
{
	int j;

	if (remalloc_the_line(line, size_to_add(*pt_buff)) == -1)
		return (-1);
	j = 0;
	while ((*pt_buff)[j] != '\n' && (*pt_buff)[j] != '\0')
	{
		(*line)[i] = (*pt_buff)[j];
		i++;
		j++;
	}
	if ((*pt_buff)[j] == '\n')
	{
		j++;
		*pt_buff = &((*pt_buff)[j]);
		return (1);
	}
	**pt_buff = '\0';
	return (0);
}

int				ft_check(int ret, char **line)
{
	if (ret == -1)
		return (-1);
	if (ret == 0 && (*line)[0] == '\0')
		return (0);
	if (ret == 0)
		return (1);
	return (2);
}

int				get_next_line(const int fd, char **line)
{
	static char stat_buff[BUFF_SIZE] = {'\0'};
	static char *pt_buff = NULL;
	int			ret;

	if (pt_buff == NULL)
		pt_buff = stat_buff;
	if (line == NULL || fd < 0)
		return (-1);
	if ((*line = (char *)malloc(1)) == NULL)
		return (-1);
	(*line)[0] = '\0';
	if (*pt_buff != '\0' && \
		(ret = ft_empty_the_buffer(line, &pt_buff, 0)) != 0)
		return (ret);
	while (1)
	{
		ft_memset(stat_buff, 0, BUFF_SIZE);
		pt_buff = stat_buff;
		ret = read(fd, stat_buff, BUFF_SIZE);
		if (ft_check(ret, line) != 2)
			return (ft_check(ret, line));
		if ((ret = ft_empty_the_buffer(line, &pt_buff, ft_strlen(*line))) != 0)
			return (ret);
	}
}
