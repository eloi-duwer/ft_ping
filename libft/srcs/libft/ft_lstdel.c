/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:18:26 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 12:45:27 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	next = (*alst)->next;
	if (next != NULL)
	{
		ft_lstdel(&next, del);
		(*alst)->next = NULL;
	}
	ft_lstdelone(alst, del);
}
