/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:48:10 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void			init_printf_context(t_printf_context *ctx, \
					const char *restrict input, va_list *list)
{
	ctx->nb_printed = 0;
	ctx->in_i = 0;
	ctx->out_i = 0;
	ctx->size_allocated = 0;
	ctx->output = NULL;
	ctx->input = input;
	ctx->list = list;
}

void			reset_flags(t_printf_context *ctx)
{
	ctx->field_width = -1;
	ctx->precision = -1;
	ctx->modifier = m_undefined;
	ctx->convertion = c_undefined;
	ctx->flags = 0;
}

t_printf_state	expand_string(t_printf_context *ctx, size_t size)
{
	char	*mem;
	size_t	to_add;

	if (size < MIN_BUFFER_EXPAND_SIZE)
		to_add = MIN_BUFFER_EXPAND_SIZE;
	else
		to_add = size + 1;
	if ((mem = (char *)ft_memalloc(sizeof(char) * \
		(ctx->size_allocated + to_add))) == NULL)
		return (error);
	ft_memcpy(mem, ctx->output, ctx->size_allocated);
	ctx->size_allocated += to_add;
	free(ctx->output);
	ctx->output = mem;
	return (true);
}
