/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:25:05 by eduwer            #+#    #+#             */
/*   Updated: 2016/12/05 13:31:03 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *pt_s1;
	unsigned char *pt_s2;

	pt_s1 = (unsigned char *)s1;
	pt_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*pt_s1 != *pt_s2)
			return ((int)(*pt_s1) - (int)(*pt_s2));
		if (*pt_s1 == '\0' && *pt_s2 == '\0')
			return (0);
		pt_s1++;
		pt_s2++;
		n--;
	}
	return (0);
}
