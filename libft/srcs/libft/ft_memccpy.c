/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:53:33 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/30 20:36:52 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *pt_dst;
	unsigned char *pt_src;

	pt_dst = (unsigned char *)dst;
	pt_src = (unsigned char *)src;
	while (n > 0)
	{
		*pt_dst = *pt_src;
		if (*pt_dst == (unsigned char)c)
		{
			pt_dst++;
			return (pt_dst);
		}
		pt_dst++;
		pt_src++;
		n--;
	}
	return (NULL);
}
