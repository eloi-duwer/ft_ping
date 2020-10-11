/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_octal_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:50:04 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static char			*itoa_base_args_conv(t_printf_context *ctx, uintmax_t nbr)
{
	int	lowercase;
	int	base;

	if (ctx->convertion == c_uhexlowcase)
	{
		lowercase = 1;
		base = 16;
	}
	else if (ctx->convertion == c_uhexuppcase)
	{
		lowercase = 0;
		base = 16;
	}
	else
	{
		lowercase = -1;
		base = 8;
	}
	return (ft_itoa_base_uintmax(nbr, base, lowercase));
}

char				*flag_hashtag_oct_hex(t_printf_context *ctx, char *str)
{
	char	*newstr;
	int		size;

	if (ctx->convertion == c_uoctal)
		size = 1;
	else
		size = 2;
	if ((newstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + size + 1))) \
			== NULL)
	{
		free(str);
		return (NULL);
	}
	newstr[0] = '0';
	if (ctx->convertion == c_uhexlowcase)
		newstr[1] = 'x';
	else if (ctx->convertion == c_uhexuppcase)
		newstr[1] = 'X';
	ft_strcpy(&(newstr[size]), str);
	free(str);
	return (newstr);
}

t_printf_state		convert_oct_hexa_print(t_printf_context *ctx, char *str)
{
	t_printf_state	ret;

	if (ctx->precision != -1 && (str = fill_to_precision_int(ctx, str)) == NULL)
		return (error);
	if (ctx->flags & FLAG_HASHTAG && (str = flag_hashtag_oct_hex(ctx, str)) \
		== NULL)
		return (error);
	if ((str = field_width(ctx, str)) == NULL)
		return (error);
	ret = append_string(ctx, str);
	free(str);
	return (ret);
}

t_printf_state		convert_octal_hexa(t_printf_context *ctx)
{
	uintmax_t	nbr;
	char		*str;

	if (ctx->convertion == c_pointer)
	{
		nbr = (uintmax_t)va_arg(*(ctx->list), void *);
		ctx->convertion = c_uhexlowcase;
	}
	else if (ctx->modifier == m_h || ctx->modifier == m_hh)
		nbr = (uintmax_t)va_arg(*(ctx->list), unsigned int);
	else if (ctx->modifier == m_l)
		nbr = (uintmax_t)va_arg(*(ctx->list), unsigned long int);
	else if (ctx->modifier == m_ll || ctx->modifier == m_q)
		nbr = (uintmax_t)va_arg(*(ctx->list), unsigned long long int);
	else if (ctx->modifier == m_j)
		nbr = (uintmax_t)va_arg(*(ctx->list), uintmax_t);
	else if (ctx->modifier == m_z || ctx->modifier == m_Z)
		nbr = (uintmax_t)va_arg(*(ctx->list), size_t);
	else if (ctx->modifier == m_t)
		nbr = (uintmax_t)va_arg(*(ctx->list), ptrdiff_t);
	else
		nbr = (uintmax_t)va_arg(*(ctx->list), unsigned int);
	if ((str = itoa_base_args_conv(ctx, nbr)) == NULL)
		return (error);
	return (convert_oct_hexa_print(ctx, str));
}
