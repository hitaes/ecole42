/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_slist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:59:54 by sgang             #+#    #+#             */
/*   Updated: 2021/12/12 18:09:58 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	slist_ppback(t_slist *list, void *data)
{
	t_snode	*newnode;

	newnode = ft_calloc(1, sizeof(t_snode), 0);
	newnode->data = data;
	list->tail->next = newnode;
	list->tail = list->tail->next;
	return ;
}

t_slist	*slist_new_list()
{
	t_slist	*list;

	list = ft_calloc(1, sizeof(t_slist), 0);
	list->head = ft_calloc(1, sizeof(t_snode), 0);
	list->tail = list->head;
	return (list);
}

void	slist_pback(t_snode **slist, void *data)
{
	t_snode	*node;
	t_snode	*iter;

	node = ft_calloc(1, sizeof(t_snode), 0);
	ft_memset((char *)node, sizeof(t_snode), 0);
	node->data = data;
	if (!*slist)
		*slist = node;
	else
	{
		iter = *slist;
		while (iter->next)
			iter = iter->next;
		iter->next = node;
	}
	return ;
}
