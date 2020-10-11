/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:16:22 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 12:11:14 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int	ft_lenght(int nb)
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

static int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		i;

	if ((result = (char *)malloc(sizeof(char) * (ft_lenght(n) + 1))) == NULL)
		return (NULL);
	result[ft_lenght(n)] = '\0';
	if (n < 0)
		result[0] = '-';
	i = ft_lenght(n) - 1;
	while (n > 9 || n < -9)
	{
		result[i] = (char)(ft_abs(n % 10) + 48);
		n /= 10;
		i--;
	}
	result[i] = (char)(ft_abs(n) + 48);
	return (result);
}
