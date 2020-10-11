/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:56:20 by eduwer            #+#    #+#             */
/*   Updated: 2016/12/14 15:04:19 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_power(double nb, unsigned int power)
{
	double mem;

	if (power == 2)
		return (nb * nb);
	if (power == 3)
		return (nb * nb * nb);
	if (power == 0)
		return (1);
	mem = nb;
	while (power > 1)
	{
		nb *= mem;
		power--;
	}
	return (nb);
}
