/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:10:24 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/12 10:38:56 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_squre(int base, int exponent)
{
	if (exponent == 0)
		return (1);
	else
		return (base * ft_squre(base, exponent - 1));
}

int ft_get_exponent(int base, int argument)
{
	if (base > argument)
		return 0;
	else
		return 1 + ft_get_exponent(base, argument / base);
}

void ft_combine(stack *s_a, stack *s_b, int exponent)
{
	printf("✅s_ah: %d, s_bh: %d %d\n", s_a->head->value, s_b->head->value, exponent);
}
void ft_divider(stack *s_a, stack *s_b, int exponent)
{
	int j;
	int i;

	j = 0;
	i = s_a->count / ft_squre(2, exponent);
	if (exponent > 0)
		ft_divider(s_a, s_b, exponent - 1);
	while (i-- > 0)
	{
		j = ft_squre(2, exponent);
		printf("✅this is the j: %d, exponent: %d\n", j, exponent);
		while (j-- > 0)
		{
			printf("✅sav: %d, sbv: %d\n", s_a->head->value, s_b->head->value);
			ft_combine(s_a, s_b, exponent);
		}
	}
}

// int ft_get_place(stack *s_a, int v)
// {
// 	int place;
// 	node *tmp_n;

// 	place = 0;
// 	while (place++ < s_a->count)
// 	{
// 		tmp_n = tmp_n->next;
// 		if (tmp_n->value < v)
// 			break;
// 	}
// 	return (place);
// }

// void ft_agamotto_eye(stack *s_a, stack *s_b)
// {
// 	printf("✅place: %d\n", ft_get_place(s_a, s_b->head->value));
// }

// void ft_sorting_all(stack *s_a, stack *s_b)
// {
// 	int tmp_count;

// 	tmp_count = s_a->count / 2;
// 	while (tmp_count-- > 0)
// 		pb(s_a, s_b);
// 	ft_divider(s_a, s_b, ft_get_exponent(2, s_a->count));
// }

void ft_sorting(stack *s_a, stack *s_b)
{
	if (s_a->count == 2)
		ft_sorting_two(s_a);
	else if (s_a->count == 3)
		ft_sorting_three(s_a);
	else
		ft_sorting_five(s_a, s_b);
	// else
	// 	ft_sorting_all(s_a, s_b);
}
