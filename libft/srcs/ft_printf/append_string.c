/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/29 17:08:26 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_printf_state	append_string(t_printf_context *ctx, const char *str)
{
	return (append_string_size(ctx, str, ft_strlen(str)));
}

t_printf_state	append_string_size(t_printf_context *ctx, const char *str, \
	int n)
{
	if (ctx->out_i + n >= (ctx->size_allocated) &&
			(expand_string(ctx, n)) == error)
		return (error);
	ft_memcpy(&(ctx->output[ctx->out_i]), str, n);
	ctx->out_i += n;
	ctx->output[ctx->out_i] = '\0';
	return (true);
}
