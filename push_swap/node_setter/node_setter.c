/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 00:56:14 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/23 17:46:48 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

node *create_node(int v_num)
{
	node *n;

	n = (node *)malloc(sizeof(node));
	if (!(n))
		return NULL;
	n->value = v_num;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}

void stack_init(stack *stk, node *new_node)
{
	if (!(stk->head))
		stk->head = new_node;
	else
	{
		if (!(stk->tail))
		{
			stk->tail = new_node;
			stk->head->next = stk->tail;
			stk->tail->prev = stk->head;
		}
		else
		{
			new_node->prev = stk->tail;
			stk->tail->next = new_node;
			stk->tail = new_node;
		}
		stk->head->prev = stk->tail;
		stk->tail->next = stk->head;
	}
	stk->count++;
}

void ft_append_s_el(stack *s_a, int v)
{
	int *tmp;
	int i;

	i = -1;
	tmp = s_a->s_list;
	s_a->s_list_count++;
	s_a->s_list = (int *)malloc(sizeof(int) * s_a->s_list_count);
	if (!(s_a->s_list))
		exit(1);
	while (++i < s_a->s_list_count - 1)
		s_a->s_list[i] = tmp[i];
	s_a->s_list[i] = v;
	if (tmp)
	{
		free(tmp);
		tmp = 0;
	}
}

void ft_find_sequence(stack *s_a, int els, int *v_nums)
{
	int i;
	int se;

	i = -1;
	se = 0;
	while (++i < els - 1)
	{
		if (v_nums[i] < v_nums[i + 1])
		{
			se++;
			if (se >= 3)
			{
				if (se == 3)
					for (int j = 2; j >= 0; j--)
						ft_append_s_el(s_a, v_nums[i - j]);
				else
					ft_append_s_el(s_a, v_nums[i]);
			}
		}
		else
			se = 0;
	}
}

void node_setter(stack *s_a, int the_number_of_els, int *v_nums)
{
	int i;

	i = -1;
	ft_find_sequence(s_a, the_number_of_els, v_nums);
	while (++i < the_number_of_els)
		stack_init(s_a, create_node(*(v_nums + i)));
}
