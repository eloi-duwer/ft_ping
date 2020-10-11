/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:48:21 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_printf_state	main_loop(t_printf_context *ctx)
{
	size_t	next_percent;

	while (ctx->input[ctx->in_i] != '\0')
	{
		next_percent = to_next_percent(ctx);
		if (next_percent > 0 && append_string_size(ctx, \
			&(ctx->input[ctx->in_i]), next_percent) == error)
			return (error);
		else if (next_percent == 0 && begin_percent_process(ctx) == error)
			return (error);
		ctx->in_i += next_percent;
	}
	return (true);
}

size_t			to_next_percent(t_printf_context *ctx)
{
	size_t	i;

	i = 0;
	while (ctx->input[ctx->in_i + i] != '\0' && \
		ctx->input[ctx->in_i + i] != '%')
		++i;
	return (i);
}
