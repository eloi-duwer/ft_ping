/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:00:30 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:36:28 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_abs(int nb)
{
	if (nb > 0)
		return ((unsigned int)nb);
	return ((unsigned int)(nb * -1));
}

uintmax_t		ft_intmax_abs(intmax_t nb)
{
	if (nb < 0)
		return ((uintmax_t)-nb);
	return ((uintmax_t)nb);
}
