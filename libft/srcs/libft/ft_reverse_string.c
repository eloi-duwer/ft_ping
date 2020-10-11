/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 23:35:14 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/17 23:39:45 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_reverse_string(unsigned char *str, size_t length)
{
	size_t	i;
	char	mem;

	i = 0;
	while (i < length / 2)
	{
		mem = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = mem;
		++i;
	}
}
