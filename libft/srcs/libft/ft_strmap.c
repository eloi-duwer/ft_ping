/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:54:53 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 17:20:19 by eduwer           ###   ########.fr       */
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
		i++;
		s++;
	}
	return (i);
}

char			*ft_strmap(char const *s, char (*f)(char))
{
	char	*pt_s;
	char	*newstr;
	int		i;

	if (s == NULL)
		return (NULL);
	pt_s = (char *)s;
	if ((newstr = (char *)malloc(sizeof(char) * (ft_strlen(pt_s) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*pt_s != '\0')
	{
		newstr[i] = f(*pt_s);
		i++;
		pt_s++;
	}
	newstr[i] = '\0';
	return (newstr);
}
