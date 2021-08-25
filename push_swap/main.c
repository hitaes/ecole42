/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:27:43 by taeskim           #+#    #+#             */
/*   Updated: 2021/08/25 17:57:22 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	s_a;
	t_stack	s_b;
	int		the_number_of_els;
	int		*v_nums;
	char	**v_strs;

	ft_t_stack_init(&s_a);
	ft_t_stack_init(&s_b);
	the_number_of_els = ft_get_count(argc, argv, ' ');
	v_strs = parser_input(argc, argv, the_number_of_els, ' ');
	v_nums = validator(the_number_of_els, v_strs, ' ');
	t_node_setter(&s_a, the_number_of_els, v_nums);
	ft_sorting(&s_a, &s_b);
	return (0);
}
