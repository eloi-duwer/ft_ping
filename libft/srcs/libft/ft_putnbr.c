/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:02:40 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 11:06:34 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void		ft_putnbr(int n)
{
	char c;

	if (n < 0)
		write(1, "-", 1);
	if (n > 9 || n < -9)
		ft_putnbr(ft_abs(n / 10));
	n %= 10;
	c = (char)(ft_abs(n) + 48);
	write(1, &c, 1);
}
