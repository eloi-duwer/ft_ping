/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:57:06 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 13:01:05 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *pt_dst;
	char *pt_src;

	if (dst < src)
		ft_memcpy(dst, src, n);
	else
	{
		pt_dst = (char *)dst;
		pt_src = (char *)src;
		while (n > 0)
		{
			n--;
			pt_dst[n] = pt_src[n];
		}
	}
	return (dst);
}
