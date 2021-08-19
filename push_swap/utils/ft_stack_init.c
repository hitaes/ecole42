/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:47:50 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/19 16:05:42 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_stack_init(stack *u_stack)
{
	u_stack->count = 0;
	u_stack->head = NULL;
	u_stack->tail = NULL;
	u_stack->s_count = 1;
	u_stack->s_index = 0;
}
