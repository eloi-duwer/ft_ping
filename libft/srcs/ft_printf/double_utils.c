/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:12:37 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

long double		ldouble_power(long double nbr, unsigned int power)
{
	long double	ret;

	if (power == 0)
		return (1.0f);
	ret = nbr;
	while (power > 1)
	{
		ret *= nbr;
		power--;
	}
	return (ret);
}

unsigned int	get_ldouble_magnitude(long double nbr)
{
	unsigned int	ret;

	ret = 0;
	while (nbr >= 10.0 || nbr <= -10.0)
	{
		nbr /= 10.0f;
		ret++;
	}
	return (ret);
}

unsigned int	get_ldouble_last_digit(long double *nbr)
{
	unsigned int	ret;
	unsigned int	magnitude;
	long double		nbr_substract;

	if (*nbr < 1.0 && *nbr > -1.0)
		return (0);
	ret = 0;
	magnitude = get_ldouble_magnitude(*nbr);
	nbr_substract = ldouble_power(10.0f, magnitude);
	while (get_ldouble_magnitude(*nbr) == magnitude && \
		(*nbr >= 1.0 || *nbr <= -1.0))
	{
		*nbr -= nbr_substract;
		ret++;
	}
	return (ret);
}
