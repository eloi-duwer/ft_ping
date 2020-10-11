/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/03/02 18:11:29 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static t_printf_state	convert_string_wchart()
{
	return (error);
}

t_printf_state			convert_string(t_printf_context *ctx)
{
	const char		*str;
	char			*strwidth;
	t_printf_state	ret;

	if (ctx->modifier == m_l)
		return (convert_string_wchart());
	str = va_arg(*(ctx->list), const char *);
	if (ctx->precision == -1)
		ctx->precision = ft_strlen(str);
	if ((strwidth = (char *)ft_memalloc(sizeof(char) * \
		(ctx->precision + 1))) == NULL)
		return (error);
	ft_memcpy(strwidth, str, ctx->precision);
	if ((strwidth = field_width(ctx, strwidth)) == NULL)
		return (error);
	ret = append_string(ctx, strwidth);
	free(strwidth);
	return (ret);
}
