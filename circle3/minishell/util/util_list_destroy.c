/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:21:43 by sgang             #+#    #+#             */
/*   Updated: 2021/12/18 20:11:36 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	dlist_delete_node(t_dnode *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	node = NULL;
	return ;
}

void	list_double_destroy(t_dlist *list)
{
	t_dnode	*iter;
	t_dnode	*temp;

	if (!list)
		return ;
	iter = list->head->next;
	while (iter != list->tail)
	{
		temp = iter;
		iter = iter->next;
		dlist_delete_node(temp);
	}
	free(list->head);
	free(list->tail);
	free(list);
	return ;
}