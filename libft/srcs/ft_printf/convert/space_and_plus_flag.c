/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_and_plus_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:07:05 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static char	*space_flag(char *str)
{
	char	*newstr;
	size_t	length;

	length = ft_strlen(str);
	if (str[0] == '-')
		return (str);
	else if ((newstr = (char *)ft_memalloc(sizeof(char) * \
		(length + 2))) == NULL)
	{
		free(str);
		return (NULL);
	}
	newstr[0] = ' ';
	ft_memcpy(&(newstr[1]), str, length);
	free(str);
	return (newstr);
}

static char	*plus_flag(char *str)
{
	char	*newstr;
	size_t	length;

	length = ft_strlen(str);
	if (str[0] == '-')
		return (str);
	else if ((newstr = (char *)ft_memalloc(sizeof(char) * \
		(length + 2))) == NULL)
	{
		free(str);
		return (NULL);
	}
	newstr[0] = '+';
	ft_memcpy(&(newstr[1]), str, length);
	free(str);
	return (newstr);
}

char		*space_and_plus_flag(t_printf_context *ctx, char *str)
{
	if (ctx->flags & FLAG_PLUS)
		return (plus_flag(str));
	else if (ctx->flags & FLAG_SPACE)
		return (space_flag(str));
	else
		return (str);
}
