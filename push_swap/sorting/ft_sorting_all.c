/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:12:38 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/18 17:53:04 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_to_base(stack *stk, char direction)
{
	int start;

	start = 0;
	if (direction == 'a')
	{
		start = ft_get_the_smallest_num(stk);
		if ((stk->count + 1) / 2 <= ft_get_index(stk, start))
			while (stk->head->value != start)
				rra(stk);
		else
			while (stk->head->value != start)
				ra(stk);
	}
	else
	{
		start = ft_get_the_biggest_num(stk);
		if ((stk->count + 1) / 2 <= ft_get_index(stk, start))
			while (stk->head->value != start)
				rrb(stk);
		else
			while (stk->head->value != start)
				rb(stk);
	}
}

void ft_sorting_all(stack *s_a, stack *s_b)
{
	int counter;

	counter = (s_a->count / 2) + 1;
	while (--counter)
		ft_agamotto_eye(s_b, s_a, 'd', counter);
	// while (s_a->count)
	// 	pb(s_a, s_b);
	// while (s_b->count)
	// 	ft_agamotto_eye(s_a, s_b, 'a', s_b->count);
	// ft_to_base(s_a, 'a');

	// counter = (s_b->count / 2) + 1;
	// ft_to_base(s_b, 'd');
	// counter = (s_b->count / 2) + 1;
	// while (s_b->count)
	// 	ft_agamotto_eye(s_a, s_b, 'a', s_b->count);

	// ft_to_base(s_a, 'a');
	// while (--counter)
	// 	pb(s_a, s_b);
	// while (s_a->count)
	// ft_agamotto_eye(s_b, s_a, 'd', s_a->count);
	// counter = (s_b->count / 2) + 1;
	// while (--counter)
	// 	pa(s_b, s_a);
	// while (s_b->count)
	// 	ft_agamotto_eye(s_a, s_b, 'a', s_b->count);

	// while (s_b->count)
	// 	pa(s_b, s_a);
	// ft_to_base(s_a, 'a');

	// while (s_a->count)
	// 	pb(s_a, s_b);
	// counter = (s_b->count / 2) + 1;
	// while (--counter)
	// {
	// 	ft_stack_mover(&s_tmp, s_b->head);
	// 	ft_remove_node(s_b);
	// }
	// while (s_tmp.count)
	// 	ft_agamotto_eye(s_a, &s_tmp, 'a', s_tmp.count);
	// while (s_b->count)
	// 	ft_agamotto_eye(s_a, s_b, 'a', s_b->count);
	// ft_to_base(s_a, 'a');
	// while (--counter)
	// 	s_a->head = s_a->head->next;

	// ft_agamotto_eye(s_b, &s_tmp, 'd', s_tmp.count);
	// ft_agamotto_eye(s_b, &s_tmp, 'd', s_tmp.count);
	// ft_to_base(s_b, 'd');
	// while (s_a->count)
	// 	pb(s_a, s_b);
	// ft_stack_init(&s_tmp);
	// counter = (s_b->count / 2) + 1;
	// while (--counter)
	// {
	// ft_remove_node(s_b);
	// }
	// while (s_tmp.count)
	// 	ft_agamotto_eye(s_a, &s_tmp, 'a', s_tmp.count);
	// while (s_b->count)
	// 	ft_agamotto_eye(s_a, s_b, 'a', s_b->count);
	// ft_to_base(s_a, 'a');
	// while (s_a->count)
	// 	pb(s_a, s_b);

	// while (s_a->count)
	// 	ft_agamotto_eye(s_b, s_a, 'd', s_a->count);
	// printf("✅%d\n", s_a->head->value);
	// printf("✅%d\n", s_a->head->next->value);
	// s_a->count = counter - s_b->count;
}
