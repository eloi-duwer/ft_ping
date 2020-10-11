/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:51:58 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/06 18:39:30 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char *pt_src;
	char *pt_dst;

	pt_src = (char *)src;
	pt_dst = dst;
	while (*pt_src != '\0')
	{
		*pt_dst = *pt_src;
		pt_src++;
		pt_dst++;
	}
	*pt_dst = '\0';
	return (dst);
}
