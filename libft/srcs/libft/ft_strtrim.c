/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:04:59 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 17:27:57 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static char		*jump_space(char *s)
{
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s != '\0')
		s++;
	return (s);
}

static size_t	ft_strlen(char *s, char *end)
{
	size_t i;

	i = 0;
	while (s != end)
	{
		s++;
		i++;
	}
	return (i);
}

static char		*ft_fill(char *s, char *end, char *newstr)
{
	char *pt_start;

	pt_start = newstr;
	while (s != end)
	{
		*newstr = *s;
		newstr++;
		s++;
	}
	*newstr = '\0';
	return (pt_start);
}

char			*ft_strtrim(char const *s)
{
	char	*pt_s;
	char	*pt_start;
	char	*pt_end;
	char	*newstr;

	if (s == NULL)
		return (NULL);
	pt_s = (char *)s;
	pt_start = jump_space(pt_s);
	pt_s = pt_start;
	pt_end = pt_s;
	while (*pt_s != '\0')
	{
		while (*pt_s != ' ' && *pt_s != '\n' && *pt_s != '\t' && *pt_s != '\0')
		{
			pt_s++;
			pt_end = pt_s;
		}
		pt_s = jump_space(pt_s);
	}
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(pt_start, pt_end) + 1));
	if (newstr == NULL)
		return (NULL);
	return (ft_fill(pt_start, pt_end, newstr));
}
