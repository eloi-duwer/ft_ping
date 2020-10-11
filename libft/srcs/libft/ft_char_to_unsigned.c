/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:53:27 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:29:16 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_char_to_unsigned(char *str)
{
	unsigned char	*ret;
	size_t			i;
	size_t			length;

	length = ft_strlen(str);
	ret = (unsigned char *)ft_memalloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < length)
	{
		ret[i] = (unsigned char)str[i];
		++i;
	}
	return (ret);
}
