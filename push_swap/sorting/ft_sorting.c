/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:10:24 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/08 20:46:27 by pac-man          ###   ########.fr       */
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
		// printf("✅before i: %d, exponent: %d\n", i, exponent);
		j = ft_squre(2, exponent);
		while (j-- > 0)
			rr(s_a, s_b);
	}
}

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
