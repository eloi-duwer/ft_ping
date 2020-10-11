/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:18:55 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:30:56 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strtoupper(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		str[i] = ft_toupper(str[i]);
		++i;
	}
}
