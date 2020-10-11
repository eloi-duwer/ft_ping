/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exposed_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:53:31 by eduwer            #+#    #+#             */
/*   Updated: 2020/03/02 22:11:18 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int	ft_printf(const char *restrict str, ...)
{
	va_list				list;
	t_printf_context	ctx;

	va_start(list, str);
	init_printf_context(&ctx, str, &list);
	reset_flags(&ctx);
	if (main_loop(&ctx) == error)
		return (-1);
	va_end(list);
	ft_putstr(ctx.output);
	free(&(ctx.output[0]));
	return (ctx.out_i);
}

int	ft_snprintf(char *str, size_t size, const char *restrict format, ...)
{
	va_list				list;
	t_printf_context	ctx;

	va_start(list, format);
	init_printf_context(&ctx, format, &list);
	reset_flags(&ctx);
	if (size != 0 && str == NULL)
		return (-1);
	if (main_loop(&ctx) == error)
		return (-1);
	va_end(list);
	if (str != NULL)
	{
		ft_bzero(str, size);
		ft_memcpy(str, ctx.output, size < ctx.out_i ? size : ctx.out_i);
	}
	free(&(ctx.output[0]));
	return (ctx.out_i);
}

int	ft_asprintf(char **pstr, const char *restrict format, ...)
{
	va_list				list;
	t_printf_context	ctx;

	va_start(list, format);
	init_printf_context(&ctx, format, &list);
	reset_flags(&ctx);
	if (main_loop(&ctx) == error)
		return (-1);
	va_end(list);
	*pstr = ctx.output;
	return (ctx.out_i);
}

int	ft_fdprintf(int fd, const char *restrict format, ...)
{
	va_list				list;
	t_printf_context	ctx;

	va_start(list, format);
	init_printf_context(&ctx, format, &list);
	reset_flags(&ctx);
	if (main_loop(&ctx) == error)
		return (-1);
	va_end(list);
	ft_putstr_fd(ctx.output, fd);
	free(&(ctx.output[0]));
	return (ctx.out_i);
}
