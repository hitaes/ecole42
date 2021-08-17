/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:14:25 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/17 17:54:11 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_get_the_smallest_num(stack *to)
{
	int i;
	int mini;
	node *tmp_n;

	i = -1;
	tmp_n = to->head;
	if (!(tmp_n))
		return (0);
	mini = tmp_n->value;
	while (++i < to->count - 1)
	{
		tmp_n = tmp_n->next;
		if (mini > tmp_n->value)
			mini = tmp_n->value;
	}
	return (mini);
}

int ft_get_the_biggest_num(stack *to)
{
	int i;
	int big;
	node *tmp_n;

	i = -1;
	tmp_n = to->head;
	if (!(tmp_n))
		return (0);
	big = tmp_n->value;
	while (++i < to->count - 1)
	{
		tmp_n = tmp_n->next;
		if (big < tmp_n->value)
			big = tmp_n->value;
	}
	return (big);
}

int ft_get_index(stack *stk, int v)
{
	int index;
	node *tmp_n;

	index = -1;
	tmp_n = stk->head;
	while (++index < stk->count)
	{
		if (tmp_n->value == v)
			break;
		tmp_n = tmp_n->next;
	}
	if (index == stk->count)
		index = 0;
	return (index);
}

int ft_get_place(stack *to, int v, char direction)
{
	int indicator;
	int start;
	node *tmp_n;

	indicator = -1;
	start = direction == 'a' ? ft_get_the_smallest_num(to) : ft_get_the_biggest_num(to);
	tmp_n = to->head;
	if (direction == 'a')
	{
		if (to->count >= 2)
		{
			while (tmp_n->value != start)
				tmp_n = tmp_n->next;
			while (++indicator < to->count)
			{
				if (tmp_n->value > v)
					break;
				tmp_n = tmp_n->next;
			}
			indicator = ft_get_index(to, tmp_n->prev->value) + 1;
		}
		else
			indicator = 0;
	}
	else
	{
		if (to->count >= 2)
		{
			while (tmp_n->value != start)
				tmp_n = tmp_n->next;
			while (++indicator < to->count)
			{
				if (tmp_n->value < v)
					break;
				tmp_n = tmp_n->next;
			}
			indicator = ft_get_index(to, tmp_n->prev->value) + 1;
		}
		else
			indicator = 0;
	}
	return (indicator);
}
