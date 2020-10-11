/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/03/02 21:48:31 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static char	*add_spaces(char *str, int length, int field_width)
{
	char	*newstr;

	if ((newstr = (char *)ft_memalloc(sizeof(char) * \
		(field_width + 1))) == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_memset(newstr, ' ', field_width - length);
	ft_memcpy(&(newstr[field_width - length]), str, length);
	free(str);
	return (newstr);
}

static char	*flag_minus(char *str, int length, int field_width)
{
	char	*newstr;

	if ((newstr = (char *)ft_memalloc(sizeof(char) * \
		(field_width + 1))) == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_memcpy(newstr, str, length);
	ft_memset(&(newstr[length]), ' ', field_width - length);
	free(str);
	return (newstr);
}

static char	*flag_zero(t_printf_context *ctx, char *str, int length)
{
	return (precision_and_zero_padding(ctx, str, ctx->field_width - length));
}

char		*field_width(t_printf_context *ctx, char *str)
{
	int	length;

	length = ft_strlen(str);
	if (length >= ctx->field_width)
		return (str);
	else if (ctx->flags & FLAG_MINUS)
		return (flag_minus(str, length, ctx->field_width));
	else if (ctx->flags & FLAG_ZERO && \
		!((ctx->convertion == c_int || ctx->convertion == c_uoctal || \
			ctx->convertion == c_uint || ctx->convertion == c_uhexlowcase \
			|| ctx->convertion == c_uhexuppcase) && ctx->precision != -1))
		return (flag_zero(ctx, str, length));
	else
		return (add_spaces(str, length, ctx->field_width));
}
