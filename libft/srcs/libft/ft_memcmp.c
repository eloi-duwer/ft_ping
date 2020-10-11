/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:09:03 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/08 17:17:29 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pt_s1;
	unsigned char	*pt_s2;

	pt_s1 = (unsigned char *)s1;
	pt_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*pt_s1 != *pt_s2)
			return ((int)(*pt_s1) - (int)(*pt_s2));
		pt_s1++;
		pt_s2++;
		n--;
	}
	return (0);
}
