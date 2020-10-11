/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:31:54 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 17:43:43 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_putstr_fd(char const *s, int fd)
{
	char	*pt_s;

	if (s != NULL)
	{
		pt_s = (char *)s;
		while (*pt_s != '\0')
		{
			write(fd, pt_s, 1);
			pt_s++;
		}
	}
}
