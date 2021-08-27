/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:33:03 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/27 16:41:09 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_sort(t_stack *stack)
{
	int	i;
	int	sorting_count;

	i = -1;
	sorting_count = 0;
	if (stack->count <= 1)
		return (0);
	while (++i < stack->count - 1)
	{
		if (stack->head->value > stack->head->next->value)
			return (1);
		else
			sorting_count++;
	}
	if (sorting_count == stack->count - 1)
		return (0);
	return (1);
}
