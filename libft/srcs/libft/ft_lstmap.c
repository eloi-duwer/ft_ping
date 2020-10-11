/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:51:11 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 18:47:00 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *list;

	if (lst == NULL || f == NULL)
		return (NULL);
	newlist = f(lst);
	list = newlist;
	lst = lst->next;
	while (lst != NULL)
	{
		list->next = f(lst);
		list = list->next;
		lst = lst->next;
	}
	return (newlist);
}
