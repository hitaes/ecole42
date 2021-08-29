/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:53:51 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/30 01:10:32 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	s_a;
	t_stack	s_b;
	int		the_number_of_els;

	ft_t_stack_init(&s_a);
	ft_t_stack_init(&s_b);
	if (!(argc - 1))
		exit(0);
	the_number_of_els = ft_get_count(argc, argv, ' ');
	parser_input(&s_a, argv, the_number_of_els, ' ');
	validator(&s_a, the_number_of_els, ' ');
	t_node_setter(&s_a, the_number_of_els, s_a.v_nums);
	if (validator_sorting(&s_a) == 1)
		ft_free(&s_a, STDIN_FILENO);
	ft_sorting(&s_a, &s_b);
	ft_free(&s_a, STDIN_FILENO);
	return (0);
}
