/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:47:50 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/29 22:39:18 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	ft_t_stack_init(t_stack *u_stack)
{
	u_stack->count = 0;
	u_stack->head = NULL;
	u_stack->tail = NULL;
	u_stack->v_nums = NULL;
	u_stack->v_str = NULL;
	u_stack->v_nums_count = 0;
	u_stack->v_str_count = -1;
	u_stack->s_count = 1;
	u_stack->s_index = 0;
}
