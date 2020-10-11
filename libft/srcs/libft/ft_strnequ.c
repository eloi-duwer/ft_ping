/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:05:28 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 17:23:34 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char *pt_s1;
	char *pt_s2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	pt_s1 = (char *)s1;
	pt_s2 = (char *)s2;
	while (n > 0 && *pt_s1 != '\0' && *pt_s2 != '\0')
	{
		if (*pt_s1 != *pt_s2)
			return (0);
		pt_s1++;
		pt_s2++;
		n--;
	}
	return (1);
}
