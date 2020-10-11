/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:23:54 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 17:24:16 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	int		i;

	if (s == NULL)
		return (NULL);
	if ((newstr = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		newstr[i] = s[start];
		start++;
		len--;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
