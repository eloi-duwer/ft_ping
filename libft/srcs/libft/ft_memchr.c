/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:18:50 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 15:29:37 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*tab;

	tab = (char *)s;
	while (n > 0)
	{
		if (*tab == (char)c)
			return (tab);
		n--;
		tab++;
	}
	return (NULL);
}
