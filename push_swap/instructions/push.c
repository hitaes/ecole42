/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:47:57 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/08 15:02:20 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pb(stack *from, stack *to)
{
	if (from->count)
	{
		ft_append_node(to, from->head);
		ft_remove_node(from);
		ft_putstr("pb");
		ft_putchar('\n');
	}
}

void pa(stack *from, stack *to)
{
	if (from->count)
	{
		ft_append_node(to, from->head);
		ft_remove_node(from);
		ft_putstr("pa");
		ft_putchar('\n');
	}
}

void pp(stack *from, stack *to)
{
	node *tmp_from;
	node *tmp_to;

	tmp_from = from->head;
	tmp_to = to->head;
	if (from->count && to->count)
	{
		ft_remove_node(from);
		ft_remove_node(to);
		ft_append_node(to, tmp_from);
		ft_append_node(from, tmp_to);
		ft_putstr("pp");
		ft_putchar('\n');
	}
}
