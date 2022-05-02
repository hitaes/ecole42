/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimtaeseon <kimtaeseon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 00:56:14 by pac-man           #+#    #+#             */
/*   Updated: 2022/03/20 17:38:36 by kimtaeseon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

t_node	*create_t_node(int v_num)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!(n))
		return (NULL);
	n->value = v_num;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}

void	t_stack_init(t_stack *stk, t_node *new_t_node)
{
	if (!(stk->head))
		stk->head = new_t_node;
	else
	{
		if (!(stk->tail))
		{
			stk->tail = new_t_node;
			stk->head->next = stk->tail;
			stk->tail->prev = stk->head;
		}
		else
		{
			new_t_node->prev = stk->tail;
			stk->tail->next = new_t_node;
			stk->tail = new_t_node;
		}
		stk->head->prev = stk->tail;
		stk->tail->next = stk->head;
	}
	stk->count++;
}

void	t_node_setter(t_stack *s_a, int the_number_of_els, int *v_nums)
{
	int		i;
	t_node	*n;

	i = -1;
	while (++i < the_number_of_els)
	{
		n = create_t_node(*(v_nums + i));
		if (!(n))
			ft_free(s_a, STDERR_FILENO);
		t_stack_init(s_a, n);
	}
}
