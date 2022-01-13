/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:02:56 by sgang             #+#    #+#             */
/*   Updated: 2021/12/18 20:11:19 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_dnode	*dlist_new_node(void *data)
{
	t_dnode	*node;

	node = ft_calloc(1, sizeof(t_dnode), 0);
	node->data = data;
	return (node);
}

void	dlist_pback(t_dlist *list, void *data)
{
	t_dnode	*newnode;

	newnode = dlist_new_node(data);
	newnode->prev = list->tail->prev;
	newnode->next = list->tail;
	list->tail->prev->next = newnode;
	list->tail->prev = newnode;
	return ;
}

void	dlist_pfront(t_dlist *list, void *data)
{
	t_dnode	*newnode;

	newnode = dlist_new_node(data);
	newnode->next = list->head->next;
	newnode->prev = list->head;
	list->head->next->prev = newnode;
	list->head->next = newnode;
	return ;
}

void	dlist_init(t_dlist *list)
{
	list->head->next = list->tail;
	list->tail->prev = list->head;
	return ;
}

t_dlist	*dlist_new_list()
{
	t_dlist	*list;

	list = ft_calloc(1, sizeof(t_dlist), 0);
	list->head = ft_calloc(1, sizeof(t_dnode), 0);
	list->tail = ft_calloc(1, sizeof(t_dnode), 0);
	dlist_init(list);
	return (list);
}
