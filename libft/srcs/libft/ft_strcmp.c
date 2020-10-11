/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:25:05 by eduwer            #+#    #+#             */
/*   Updated: 2020/10/11 13:17:58 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *pt_s1;
	unsigned char *pt_s2;

	pt_s1 = (unsigned char *)s1;
	pt_s2 = (unsigned char *)s2;
	while (*pt_s1 != '\0' && *pt_s1 == *pt_s2)
	{
		pt_s1++;
		pt_s2++;
	}
	return ((int)(*pt_s1) - (int)(*pt_s2));
}
