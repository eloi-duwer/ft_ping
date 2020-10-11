/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:00:02 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/08 17:43:10 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int		ft_verif(char *big, char *little, size_t len)
{
	while (*little != '\0' && len != 0)
	{
		if (*big != *little)
			return (0);
		big++;
		little++;
		len--;
	}
	if (*little == '\0')
		return (1);
	return (0);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	char *pt_big;
	char *pt_little;

	pt_big = (char *)big;
	pt_little = (char *)little;
	if (*pt_little == '\0')
		return (pt_big);
	while (*pt_big != '\0' && len > 0)
	{
		while (*pt_big != *pt_little && *pt_big != '\0' && len > 0)
		{
			len--;
			pt_big++;
		}
		if (*pt_big == '\0' || len == 0)
			return (NULL);
		if (ft_verif(pt_big, pt_little, len) == 1)
			return (pt_big);
		pt_big++;
		len--;
	}
	return (NULL);
}
