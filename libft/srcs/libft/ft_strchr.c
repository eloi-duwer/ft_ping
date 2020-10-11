/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:21:12 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/05 10:59:50 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char *pt;

	pt = (char *)s;
	while (*pt != (char)c && *pt != '\0')
		pt++;
	if (*pt == (char)c)
		return (pt);
	else
		return (NULL);
}
