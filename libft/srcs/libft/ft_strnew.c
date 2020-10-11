/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:19:02 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/08 18:53:37 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*tab;
	size_t	i;

	if ((tab = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
