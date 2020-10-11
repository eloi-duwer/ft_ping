/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/03/02 22:03:04 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

/*
**	intmax_t est le plus grand type d'entrier possible,
**	donc c'est safe de caster vers ce type (pas de perte de donnees)
**	pour le flag h et hh: on cast en int et pas short car warning,
**	pour des raisons d'optimisations (alignement de memoire)
**	les types plus petits sont castés en int
*/

static t_printf_state	convert_int_print(t_printf_context *ctx, char *str)
{
	t_printf_state	ret;

	if (ctx->precision != -1 && (str = fill_to_precision_int(ctx, str)) == NULL)
		return (error);
	if ((str = space_and_plus_flag(ctx, str)) == NULL)
		return (error);
	if ((str = field_width(ctx, str)) == NULL)
		return (error);
	ret = append_string(ctx, str);
	free(str);
	return (ret);
}

t_printf_state			convert_int(t_printf_context *ctx)
{
	intmax_t	nbr;
	char		*str;

	if (ctx->modifier == m_h || ctx->modifier == m_hh)
		nbr = (intmax_t)va_arg(*(ctx->list), int);
	else if (ctx->modifier == m_l)
		nbr = (intmax_t)va_arg(*(ctx->list), long int);
	else if (ctx->modifier == m_ll || ctx->modifier == m_q)
		nbr = (intmax_t)va_arg(*(ctx->list), long long int);
	else if (ctx->modifier == m_j)
		nbr = (intmax_t)va_arg(*(ctx->list), intmax_t);
	else if (ctx->modifier == m_z || ctx->modifier == m_Z)
		nbr = (intmax_t)va_arg(*(ctx->list), ssize_t);
	else if (ctx->modifier == m_t)
		nbr = (intmax_t)va_arg(*(ctx->list), ptrdiff_t);
	else
		nbr = (intmax_t)va_arg(*(ctx->list), int);
	if ((str = ft_itoa_intmax(nbr)) == NULL)
		return (error);
	return (convert_int_print(ctx, str));
}

char					*fill_to_precision_int(t_printf_context *ctx, char *str)
{
	int	length;

	length = ft_strlen(str);
	if (str[0] == '-')
		length--;
	else if (str[0] == '0' && ctx->precision == 0)
	{
		str[0] = '\0';
	}
	if (length >= ctx->precision)
		return (str);
	return (precision_and_zero_padding(ctx, str, ctx->precision - length));
}

char					*precision_and_zero_padding(t_printf_context *ctx, \
							char *str, int nb_to_add)
{
	char	*newstr;
	int		i;
	int		length;

	length = ft_strlen(str) + nb_to_add + 1;
	if ((newstr = (char *)ft_memalloc(sizeof(char) * length)) == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	if ((ctx->convertion == c_int || ctx->convertion == c_scilowcase || \
		ctx->convertion == c_sciuppcase || ctx->convertion == c_lowdouble || \
			ctx->convertion == c_uppdouble) && str[0] == '-')
	{
		newstr[0] = str[0];
		i = 1;
	}
	ft_memset(&(newstr[i]), '0', nb_to_add);
	ft_memcpy(&(newstr[nb_to_add + i]), &(str[i]), length - nb_to_add - i);
	free(str);
	return (newstr);
}
