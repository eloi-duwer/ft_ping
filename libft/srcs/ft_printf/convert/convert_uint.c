/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:50:24 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

/*
**	uintmax_t est le plus grand type d'entrier possible,
**	donc c'est safe de caster vers ce type (pas de perte de donnees)
**	pour le flag h et hh: on cast en int et pas short car warning,
**	pour des raisons d'optimisations (alignement de memoire)
**	les types plus petits sont castés en int
*/

t_printf_state	convert_uint(t_printf_context *ctx)
{
	intmax_t	nbr;
	char		*str;

	if (ctx->modifier == m_h || ctx->modifier == m_hh)
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
		nbr = (intmax_t)va_arg(*(ctx->list), unsigned int);
	if ((str = ft_itoa_uintmax(nbr)) == NULL)
		return (error);
	return (convert_uint_print(ctx, str));
}

t_printf_state	convert_uint_print(t_printf_context *ctx, char *str)
{
	t_printf_state	ret;

	if (ctx->precision != -1 && (str = fill_to_precision_int(ctx, str)) == NULL)
		return (error);
	if ((str = field_width(ctx, str)) == NULL)
		return (error);
	ret = append_string(ctx, str);
	free(str);
	return (ret);
}
