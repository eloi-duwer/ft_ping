/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:12:04 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/07 20:48:07 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*src_ptr;
	char	*dst_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	while (n > 0)
	{
		*dst_ptr = *src_ptr;
		src_ptr++;
		dst_ptr++;
		n--;
	}
	return (dst);
}
