/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:20:26 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/07 20:48:52 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char *pt_dest;
	char *pt_src;

	pt_dest = (char *)s1;
	pt_src = (char *)s2;
	while (*pt_dest != '\0')
		pt_dest++;
	while (*pt_src != '\0')
	{
		*pt_dest = *pt_src;
		pt_dest++;
		pt_src++;
	}
	*pt_dest = '\0';
	return (s1);
}
