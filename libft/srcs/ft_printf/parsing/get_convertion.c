/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_convertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:48:50 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static t_printf_state	get_other_convertions(t_printf_context *ctx)
{
	if (ctx->input[ctx->in_i] == 'x')
		ctx->convertion = c_uhexlowcase;
	else if (ctx->input[ctx->in_i] == 'X')
		ctx->convertion = c_uhexuppcase;
	else if (ctx->input[ctx->in_i] == 'e')
		ctx->convertion = c_scilowcase;
	else if (ctx->input[ctx->in_i] == 'E')
		ctx->convertion = c_sciuppcase;
	else if (ctx->input[ctx->in_i] == 'f')
		ctx->convertion = c_lowdouble;
	else if (ctx->input[ctx->in_i] == 'F')
		ctx->convertion = c_uppdouble;
	else
		return (false);
	return (true);
}

static t_printf_state	print_plain_percent(t_printf_context *ctx)
{
	int prev_percent;

	prev_percent = 0;
	while (ctx->in_i - prev_percent >= 0 && \
		ctx->input[ctx->in_i - prev_percent] != '%')
		prev_percent++;
	if (ctx->in_i - prev_percent < 0)
		return (false);
	if (append_string_size(ctx, &(ctx->input[ctx->in_i - prev_percent]), \
		prev_percent) == error)
		return (error);
	return (false);
}

t_printf_state			get_convertion(t_printf_context *ctx)
{
	if (ctx->input[ctx->in_i] == 'i' || ctx->input[ctx->in_i] == 'd')
		ctx->convertion = c_int;
	else if (ctx->input[ctx->in_i] == 'p')
		ctx->convertion = c_pointer;
	else if (ctx->input[ctx->in_i] == 's')
		ctx->convertion = c_string;
	else if (ctx->input[ctx->in_i] == 'o')
		ctx->convertion = c_uoctal;
	else if (ctx->input[ctx->in_i] == 'u')
		ctx->convertion = c_uint;
	else if (ctx->input[ctx->in_i] == 'c')
		ctx->convertion = c_char;
	else if (get_other_convertions(ctx) != true)
		return (print_plain_percent(ctx));
	ctx->in_i++;
	return (make_ze_convertion(ctx));
}
