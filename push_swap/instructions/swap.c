/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:00:25 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/25 14:18:53 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stk)
{
	t_node	*tmp_head;
	t_node	*tmp_head_next;

	tmp_head = stk->head;
	tmp_head_next = stk->head->next;
	if (stk->count >= 2)
	{
		ft_remove_t_node(stk);
		ft_remove_t_node(stk);
		ft_append_t_node(stk, tmp_head);
		ft_append_t_node(stk, tmp_head_next);
		ft_putstr("sa\n");
	}
}

void	sb(t_stack *stk)
{
	t_node	*tmp_head;
	t_node	*tmp_head_next;

	tmp_head = stk->head;
	tmp_head_next = stk->head->next;
	if (stk->count >= 2)
	{
		ft_remove_t_node(stk);
		ft_remove_t_node(stk);
		ft_append_t_node(stk, tmp_head);
		ft_append_t_node(stk, tmp_head_next);
		ft_putstr("sb\n");
	}
}

void	ss(t_stack *l_stk, t_stack *r_stk)
{
	t_node	*tmp_l_stk;
	t_node	*tmp_l_stk_next;
	t_node	*tmp_r_stk;
	t_node	*tmp_r_stk_next;

	tmp_l_stk = l_stk->head;
	tmp_l_stk_next = l_stk->head->next;
	tmp_r_stk = r_stk->head;
	tmp_r_stk_next = r_stk->head->next;
	if (l_stk->count >= 2 && r_stk->count >= 2)
	{
		ft_remove_t_node(l_stk);
		ft_remove_t_node(l_stk);
		ft_append_t_node(l_stk, tmp_l_stk);
		ft_append_t_node(l_stk, tmp_l_stk_next);
		ft_remove_t_node(r_stk);
		ft_remove_t_node(r_stk);
		ft_append_t_node(r_stk, tmp_r_stk);
		ft_append_t_node(r_stk, tmp_r_stk_next);
		ft_putstr("ss\n");
	}
}
