/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_intmax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:16:22 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:34:10 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "libft.h"

static char	convert_to_char(uintmax_t n, int is_lowercase)
{
	if (n <= 9)
		return (char)(n + 48);
	else if (n <= 36 && is_lowercase == 1)
		return ((char)(n + 87));
	else if (n <= 36 && is_lowercase == 0)
		return ((char)(n + 55));
	else
		return ('?');
}

static int	length_base(intmax_t nb, unsigned int base)
{
	int i;

	i = 1;
	while (nb > base - 1 || nb < -base + 1)
	{
		nb = nb / base;
		i++;
	}
	if (nb < 0)
		return (i + 1);
	return (i);
}

static int	ulenght_base(uintmax_t nb, unsigned int base)
{
	int i;

	i = 1;
	while (nb > base - 1)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base_uintmax(uintmax_t n, unsigned int base, \
	int is_lowercase)
{
	char	*result;
	int		i;

	i = ulenght_base(n, base);
	if ((result = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	result[i] = '\0';
	i--;
	while (n > base - 1)
	{
		result[i] = convert_to_char(n % base, is_lowercase);
		n /= base;
		i--;
	}
	result[i] = convert_to_char(n, is_lowercase);
	return (result);
}

char		*ft_itoa_base_intmax(intmax_t n, unsigned int base, \
	int is_lowercase)
{
	char	*result;
	int		i;

	i = length_base(n, base);
	if ((result = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	result[i] = '\0';
	if (n < 0)
		result[0] = '-';
	i--;
	while (n > base - 1 || n < -base + 1)
	{
		result[i] = convert_to_char(ft_intmax_abs(n % base), is_lowercase);
		n /= base;
		i--;
	}
	result[i] = convert_to_char(ft_intmax_abs(n), is_lowercase);
	return (result);
}
