/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:54:48 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/07 19:21:31 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char *pt;
	char *last_occur;

	pt = (char *)s;
	last_occur = NULL;
	if ((char)c == '\0')
	{
		while (*pt != '\0')
			pt++;
		return (pt);
	}
	while (*pt != '\0')
	{
		if (*pt == (char)c)
			last_occur = pt;
		pt++;
	}
	return (last_occur);
}
