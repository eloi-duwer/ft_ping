/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:03:51 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:32:12 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char	*pt;
	size_t	i;

	if ((pt = (char *)malloc(sizeof(char) * (size))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		pt[i] = '\0';
		i++;
	}
	return (pt);
}
