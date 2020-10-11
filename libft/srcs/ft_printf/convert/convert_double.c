/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/03/03 18:37:43 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static char		*fill_decimal_part(char *str, long double nbr, int i, \
	int length)
{
	str[i++] = '.';
	while (i < length)
	{
		nbr *= 10.0;
		str[i] = (char)(get_ldouble_last_digit(&nbr) + '0');
		++i;
	}
	return (str);
}

static char		*special_double_value(t_printf_context *ctx, char *str, \
	long double nbr)
{
	if (ctx->convertion == c_lowdouble)
	{
		if (nbr == INFINITY)
			ft_strncpy(str, "inf", 3);
		else if (nbr == -INFINITY)
			ft_strncpy(str, "-inf", 4);
		else if (nbr == NAN)
			ft_strncpy(str, "NaN", 3);
	}
	else if (ctx->convertion == c_uppdouble)
	{
		if (nbr == INFINITY)
			ft_strncpy(str, "INF", 3);
		else if (nbr == -INFINITY)
			ft_strncpy(str, "-INF", 4);
		else if (nbr == NAN)
			ft_strncpy(str, "NAN", 3);
	}
	return (str);
}

static size_t	double_length(t_printf_context *ctx, long double nbr)
{
	size_t size;

	if (nbr == INFINITY || nbr == NAN)
		return (3);
	else if (nbr == -INFINITY)
		return (4);
	size = 1;
	while (nbr >= 10.0 || nbr <= -10.0)
	{
		nbr /= 10.0;
		size++;
	}
	if (nbr < 0.0f)
		size += 1;
	if (ctx->precision == -1)
		return (size + 7);
	if (ctx->precision == 0)
		return (size);
	return (size + ctx->precision + 1);
}

static char		*longdoubletochar(t_printf_context *ctx, long double nbr)
{
	char	*ret;
	int		i;
	int		length;

	length = double_length(ctx, nbr);
	if ((ret = (char *)ft_memalloc(sizeof(char) * \
		(length + 1))) == NULL)
		return (NULL);
	if (nbr == INFINITY || nbr == -INFINITY || nbr == NAN)
		return (special_double_value(ctx, ret, nbr));
	i = 0;
	if (nbr < 0)
		i = 1;
	if (nbr < 0)
		ret[0] = '-';
	while (1)
	{
		ret[i] = (char)(get_ldouble_last_digit(&nbr) + '0');
		i++;
		if (nbr < 1.0 && nbr > -1.0)
			return (fill_decimal_part(ret, nbr, i, length));
	}
}

t_printf_state	convert_double(t_printf_context *ctx)
{
	long double		nbr;
	char			*str;
	t_printf_state	ret;

	if (ctx->modifier == m_L)
		nbr = (long double)va_arg(*(ctx->list), long double);
	else
		nbr = (long double)va_arg(*(ctx->list), double);
	if ((str = longdoubletochar(ctx, nbr)) == NULL)
		return (error);
	if ((str = space_and_plus_flag(ctx, str)) == NULL)
		return (error);
	if ((str = field_width(ctx, str)) == NULL)
		return (error);
	ret = append_string(ctx, str);
	free(str);
	return (ret);
}
