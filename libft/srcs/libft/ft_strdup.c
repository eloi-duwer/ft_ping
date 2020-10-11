/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 21:40:32 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/05 14:50:19 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char		*ft_strdup(char *src)
{
	int		nb_char;
	int		i;
	char	*newstr;

	nb_char = 0;
	while (src[nb_char] != '\0')
		nb_char++;
	newstr = malloc(sizeof(char) * (nb_char + 1));
	if (newstr == NULL)
		return (newstr);
	i = 0;
	while (i <= nb_char)
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
