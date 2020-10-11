/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:35:31 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 17:36:10 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

static void		ft_fill(char *s1, char *s2)
{
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char *newtab;
	char *pt_newtab;
	char *pt_s1;
	char *pt_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	pt_s1 = (char *)s1;
	pt_s2 = (char *)s2;
	if ((newtab = (char *)malloc(sizeof(char) * (ft_strlen(pt_s1) + \
			ft_strlen(pt_s2) + 1))) == NULL)
		return (NULL);
	pt_newtab = newtab;
	while (*s1 != '\0')
	{
		*pt_newtab = *s1;
		s1++;
		pt_newtab++;
	}
	ft_fill(pt_newtab, pt_s2);
	return (newtab);
}
