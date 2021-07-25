/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:27:43 by taeskim           #+#    #+#             */
/*   Updated: 2021/07/25 20:54:17 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int count;
	char **p_str;
	int *v_nums;
	stack s_a;

	// count = ft_get_count(argc, argv);
	p_str = parser_input(argc, argv);
	// v_nums = validator(count, p_str);
	// node_setter(&s_a, count, v_nums);
	// sorting(s_a);
	// while (s_a.head)
	// {
	// 	// ft_clean(s_a.head);
	// 	printf("✅%d\n", s_a.head->value);
	// 	s_a.head = s_a.head->next;
	// }
	// ft_clean(p_str);
	// ft_clean(v_nums);
	return (0);
}
