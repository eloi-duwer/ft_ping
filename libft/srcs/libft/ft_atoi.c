/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:33:03 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 15:08:58 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		result;
	char	*pt_str;
	int		sign;

	result = 0;
	pt_str = (char *)str;
	while (((int)(*pt_str) <= 32 || (int)(*pt_str) == 127) && (int)*pt_str > 0)
		pt_str++;
	sign = 1;
	if (*pt_str == '-' || *pt_str == '+')
	{
		if (*pt_str == '-')
			sign = -1;
		pt_str++;
	}
	while (*pt_str >= '0' && *pt_str <= '9')
	{
		result = 10 * result + ((int)(*pt_str)) - 48;
		pt_str++;
	}
	return (result * sign);
}
