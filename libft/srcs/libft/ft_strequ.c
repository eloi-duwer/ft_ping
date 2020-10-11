/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:05:28 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 17:38:45 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strequ(char const *s1, char const *s2)
{
	char *pt_s1;
	char *pt_s2;

	if (s1 != NULL && s2 != NULL)
	{
		pt_s1 = (char *)s1;
		pt_s2 = (char *)s2;
		while (*pt_s1 == *pt_s2)
		{
			if (*pt_s1 == '\0')
				return (1);
			pt_s1++;
			pt_s2++;
		}
	}
	return (0);
}
