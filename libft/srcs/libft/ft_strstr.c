/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:00:02 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/07 20:53:12 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int		ft_verif(char *big, char *little)
{
	while (*little != '\0')
	{
		if (*big != *little)
			return (0);
		big++;
		little++;
	}
	return (1);
}

char			*ft_strstr(const char *big, const char *little)
{
	char *pt_big;
	char *pt_little;

	pt_big = (char *)big;
	pt_little = (char *)little;
	if (*pt_little == '\0')
		return (pt_big);
	while (*pt_big != '\0')
	{
		while (*pt_big != *pt_little && *pt_big != '\0')
			pt_big++;
		if (*pt_big == '\0')
			return (NULL);
		if (ft_verif(pt_big, pt_little) == 1)
			return (pt_big);
		else
			pt_big++;
	}
	return (NULL);
}
