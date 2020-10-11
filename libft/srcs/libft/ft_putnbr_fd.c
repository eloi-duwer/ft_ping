/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:02:40 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 11:09:58 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void		ft_putnbr_fd(int n, int fd)
{
	char c;

	if (n < 0)
		write(fd, "-", 1);
	if (n > 9 || n < -9)
		ft_putnbr_fd(ft_abs(n / 10), fd);
	n %= 10;
	c = (char)(ft_abs(n) + 48);
	write(fd, &c, 1);
}
