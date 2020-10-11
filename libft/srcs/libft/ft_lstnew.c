/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:51:11 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 13:37:41 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void		ft_cpy(unsigned char *dst, unsigned char *src, size_t i)
{
	while (i > 0)
	{
		*dst = *src;
		dst++;
		src++;
		i--;
	}
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	unsigned char	*pt_content;
	unsigned char	*newcontent;
	t_list			*newlist;

	if ((newlist = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((newcontent = (unsigned char *)malloc(content_size)) == NULL)
		return (NULL);
	pt_content = (unsigned char *)content;
	if (pt_content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		ft_cpy(newcontent, pt_content, content_size);
		newlist->content = (void *)newcontent;
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}
