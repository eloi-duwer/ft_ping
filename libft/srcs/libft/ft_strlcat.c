/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:20:26 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/08 17:45:09 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strlen(const char *s)
{
	size_t		i;
	char		*tab;

	i = 0;
	tab = (char *)s;
	while (*tab != '\0')
	{
		tab++;
		i++;
	}
	return (i);
}

static size_t	ft_special(size_t tot_len, char *dst, char *src, int size)
{
	if (size <= (int)ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (*dst != '\0' && size > 1)
	{
		dst++;
		size--;
	}
	while (*src != '\0' && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (tot_len);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*pt_dest;
	char	*pt_src;
	size_t	tot_len;

	tot_len = ft_strlen(dst) + ft_strlen(src);
	if (size <= tot_len)
	{
		tot_len = ft_special(tot_len, dst, (char *)src, size);
		return (tot_len);
	}
	pt_dest = (char *)dst;
	pt_src = (char *)src;
	while (*pt_dest != '\0')
		pt_dest++;
	while (*pt_src != '\0' && size > 1)
	{
		*pt_dest = *pt_src;
		pt_dest++;
		pt_src++;
		size--;
	}
	*pt_dest = '\0';
	return (tot_len);
}
