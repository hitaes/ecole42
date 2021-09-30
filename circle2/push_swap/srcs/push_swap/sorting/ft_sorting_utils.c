/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:14:25 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/29 12:30:28 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_conditional_num(t_stack *to, char c)
{
	int		i;
	int		num;
	t_node	*tmp_n;

	i = -1;
	tmp_n = to->head;
	if (!(tmp_n))
		return (0);
	num = tmp_n->value;
	while (++i < to->count - 1)
	{
		tmp_n = tmp_n->next;
		if (c == 'd' && num < tmp_n->value)
			num = tmp_n->value;
		else if (c == 'a' && num > tmp_n->value)
			num = tmp_n->value;
	}
	return (num);
}

void	ft_to_base(t_stack *stk, char direction)
{
	int	start;

	start = 0;
	if (direction == 'a')
	{
		start = ft_get_conditional_num(stk, 'a');
		if ((stk->count / 2) + 1 <= ft_get_index(stk, start))
			while (stk->head->value != start)
				rra(stk, STDOUT_FILENO);
		else
			while (stk->head->value != start)
				ra(stk, STDOUT_FILENO);
	}
	else
	{
		start = ft_get_conditional_num(stk, 'd');
		if ((stk->count / 2) + 1 <= ft_get_index(stk, start))
			while (stk->head->value != start)
				rrb(stk, STDOUT_FILENO);
		else
			while (stk->head->value != start)
				rb(stk, STDOUT_FILENO);
	}
}

int	ft_get_index(t_stack *stk, int v)
{
	int		index;
	t_node	*tmp_n;

	index = -1;
	tmp_n = stk->head;
	while (++index < stk->count)
	{
		if (tmp_n->value == v)
			break ;
		tmp_n = tmp_n->next;
	}
	if (index == stk->count)
		index = 0;
	return (index);
}

int	ft_get_place(t_stack *to, int v, char direction)
{
	int		indicator;
	int		start;
	t_node	*tmp_n;

	indicator = -1;
	tmp_n = to->head;
	start = ft_get_conditional_num(to, direction);
	if (to->count >= 2)
	{
		while (tmp_n->value != start)
			tmp_n = tmp_n->next;
		while (++indicator < to->count)
		{
			if (direction == 'a')
				if (tmp_n->value > v)
					break ;
			if (direction == 'd')
				if (tmp_n->value < v)
					break ;
			tmp_n = tmp_n->next;
		}
		indicator = ft_get_index(to, tmp_n->prev->value);
	}
	return (++indicator);
}

int	ft_best_future(t_stack *to, t_stack *from, int place, int v)
{
	int	cost;
	int	b_place;

	b_place = ft_get_index(from, v);
	if ((from->count / 2) + 1 <= b_place)
		cost = from->count - b_place;
	else
		cost = b_place;
	if ((to->count / 2) + 1 <= place)
	{
		while (to->count > place++)
			cost++;
		cost++;
	}
	else
	{
		while (place--)
			cost++;
		cost++;
	}
	return (cost);
}
