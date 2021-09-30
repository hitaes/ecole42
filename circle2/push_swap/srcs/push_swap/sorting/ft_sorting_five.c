/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:11:15 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/29 12:30:16 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting_five(t_stack *s_a, t_stack *s_b)
{
	pb(s_a, s_b, STDOUT_FILENO);
	pb(s_a, s_b, STDOUT_FILENO);
	ft_sorting_three(s_a);
	while (s_b->count)
		ft_agamotto_eye(s_a, s_b, 'a', s_b->count);
	ft_to_base(s_a, 'a');
}
