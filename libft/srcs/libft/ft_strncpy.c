/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:57:43 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/04 15:06:44 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *pt_dst;
	char *pt_src;

	pt_dst = dst;
	pt_src = (char *)src;
	while (len > 0 && *pt_src != '\0')
	{
		*pt_dst = *pt_src;
		pt_dst++;
		pt_src++;
		len--;
	}
	if (len > 0)
	{
		while (len > 0)
		{
			*pt_dst = '\0';
			pt_dst++;
			len--;
		}
	}
	return (dst);
}
