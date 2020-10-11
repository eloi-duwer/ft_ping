/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:31:44 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:49:00 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static t_printf_state	test_l_ll_h_hh(t_printf_context *ctx)
{
	if (ctx->input[ctx->in_i] == 'h')
	{
		if (ctx->input[ctx->in_i + 1] == 'h')
		{
			ctx->modifier = m_hh;
			ctx->in_i++;
		}
		else
			ctx->modifier = m_L;
	}
	else if (ctx->input[ctx->in_i] == 'l')
	{
		if (ctx->input[ctx->in_i + 1] == 'l')
		{
			ctx->modifier = m_ll;
			ctx->in_i++;
		}
		else
			ctx->modifier = m_l;
	}
	else
		return (false);
	return (true);
}

t_printf_state			get_modifiers(t_printf_context *ctx)
{
	if (ctx->input[ctx->in_i] == 'q')
		ctx->modifier = m_q;
	else if (ctx->input[ctx->in_i] == 'L')
		ctx->modifier = m_L;
	else if (ctx->input[ctx->in_i] == 'j')
		ctx->modifier = m_j;
	else if (ctx->input[ctx->in_i] == 'z')
		ctx->modifier = m_z;
	else if (ctx->input[ctx->in_i] == 'Z')
		ctx->modifier = m_Z;
	else if (ctx->input[ctx->in_i] == 't')
		ctx->modifier = m_t;
	else if (test_l_ll_h_hh(ctx) != true)
		ctx->in_i--;
	ctx->in_i++;
	return (get_convertion(ctx));
}
