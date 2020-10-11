/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_intmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:16:22 by eduwer            #+#    #+#             */
/*   Updated: 2020/02/28 22:35:59 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

static int		length(intmax_t nb)
{
	int i;

	i = 1;
	while (nb > 9 || nb < -9)
	{
		nb = nb / 10;
		i++;
	}
	if (nb < 0)
		return (i + 1);
	return (i);
}

static intmax_t	intmax_abs(intmax_t nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

char			*ft_itoa_intmax(intmax_t n)
{
	char	*result;
	int		i;

	i = length(n);
	if ((result = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	result[i] = '\0';
	if (n < 0)
		result[0] = '-';
	i--;
	while (n > 9 || n < -9)
	{
		result[i] = (char)(intmax_abs(n % 10) + 48);
		n /= 10;
		i--;
	}
	result[i] = (char)(intmax_abs(n) + 48);
	return (result);
}

static int		ulenght(uintmax_t nb)
{
	int i;

	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa_uintmax(uintmax_t n)
{
	char	*result;
	int		i;

	i = ulenght(n);
	if ((result = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	result[i] = '\0';
	i--;
	while (n > 9)
	{
		result[i] = (char)((n % 10) + 48);
		n /= 10;
		i--;
	}
	result[i] = (char)(n + 48);
	return (result);
}
