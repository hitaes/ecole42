/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:10:24 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/05 16:31:58 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void ft_swap_reverse_double(stack *s_a, stack *s_b, int bundle)
// {
// 	while (bundle-- > 0)
// 	{
// 		ss(s_a, s_b);
// 		rr(s_a, s_b);
// 	}
// }

// void ft_swap_reverse_s_a(stack *s_a, int bundle)
// {
// 	while (bundle-- > 0)
// 	{
// 		sa(s_a);
// 		ra(s_a);
// 	}
// }

// void ft_swap_reverse_s_b(stack *s_b, int bundle)
// {
// 	while (bundle-- > 0)
// 	{
// 		sb(s_b);
// 		rb(s_b);
// 	}
// }

int ft_squre(int base, int exponent)
{
	if (exponent == 0)
		return (1);
	else
		return (base * ft_squre(base, exponent - 1));
}

void ft_combine(stack *s_a, stack *s_b, int exponent)
{
	int i;
	int j;

	// /*✅ i는 bundle 즉, 2 4 8 16으로 나가는 덩어리*/
	i = s_a->count / ft_squre(2, exponent);
	j = 0;
	// printf("✅before i: %d, exponent: %d\n", i, exponent);
	if (exponent > 1)
		ft_combine(s_a, s_b, exponent - 1);
	while (i-- > 0)
	{
		printf("✅before i: %d, exponent: %d\n", i, exponent);
		// if (s_a->head->value > s_a->head->next->value)
		// {
		// 	if (s_b->head->value < s_b->head->next->value)
		// 		ss(s_a, s_b);
		// 	else
		// 		sa(s_a);
		// }
		// else if (s_b->head->value < s_b->head->next->value)
		// 	sb(s_b);
		j = ft_squre(2, exponent);
		while (j-- > 0)
			rr(s_a, s_b);
	}

	// printf("------------------------\n");
	// while (i-- > 0)
	// {
	// 	j = ft_squre(2, exponent);
	// 	printf("##########################\n");
	// 	printf("✅i : %d, j : %d\n", i, j);

	// 	// while (j > 0)
	// 	// {
	// 	// 	printf("✅i : %d, j : %d\n", i, j);
	// 	// 	j--;
	// 	// }
	// }
}

// void ft_swap_node(stack *s_a, stack *s_b, int count)
// {
// 	int i;

// 	i = -1;
// 	while (++i < count)
// 	{
// 		if (s_a->head->value > s_a->head->next->value)
// 		{
// 			if (s_b->head->value < s_b->head->next->value)
// 				ft_swap_reverse_double(s_a, s_b);
// 			else
// 				ft_swap_reverse_s_a(s_a);
// 		}
// 		else if (s_a->head->value < s_a->head->next->value)
// 			ft_swap_reverse_s_b(s_b);
// 	}
// }

int ft_get_exponent(int base, int argument)
{
	if (base > argument)
		return 0;
	else
		return 1 + ft_get_exponent(base, argument / base);
}

void ft_sorting_all(stack *s_a, stack *s_b)
{
	int tmp_count;

	tmp_count = s_a->count / 2;
	while (tmp_count-- > 0)
		pb(s_a, s_b);
	ft_combine(s_a, s_b, ft_get_exponent(2, s_a->count));
}

void ft_sorting(stack *s_a, stack *s_b)
{
	if (s_a->count == 2)
		ft_sorting_two(s_a);
	else if (s_a->count == 3)
		ft_sorting_three(s_a);
	else if (s_a->count == 5)
		ft_sorting_five(s_a, s_b);
	else
		ft_sorting_all(s_a, s_b);
}
