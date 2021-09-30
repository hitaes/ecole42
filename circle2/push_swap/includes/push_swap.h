/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:44 by taeskim           #+#    #+#             */
/*   Updated: 2021/08/27 15:51:35 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

void	ft_sorting(t_stack *s_a, t_stack *s_b);
void	ft_sorting_two(t_stack *s_a);
void	ft_sorting_three(t_stack *s_a);
void	ft_sorting_five(t_stack *s_a, t_stack *s_b);
void	ft_sorting_all(t_stack *s_a, t_stack *s_b);
void	ft_insert_el(t_stack *s_a, t_stack *s_b, int place, int v);
void	ft_agamotto_eye(t_stack *to, t_stack *from, char direction, int range);
void	ft_to_base(t_stack *stk, char direction);

#endif
