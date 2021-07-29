/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:27:43 by taeskim           #+#    #+#             */
/*   Updated: 2021/07/29 17:21:37 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	stack s_a;
	stack s_b;
	int the_number_of_els;
	int *v_nums;
	char **v_strs;
	char c;

	c = ' ';
	ft_stack_init(&s_a);
	ft_stack_init(&s_b);
	the_number_of_els = ft_get_count(argc, argv, c);
	v_strs = parser_input(argc, argv, the_number_of_els, c);
	v_nums = validator(the_number_of_els, v_strs, c);
	node_setter(&s_a, the_number_of_els, v_nums);
	// printf("✅1: in main, s_a->head: %lld\n", (long long)s_a.head);
	ft_sorting(&s_a, &s_b);
	// printf("✅2: in main, s_a->head: %lld\n", (long long)s_a.head);

	// while (s_a.count--)
	// {
	// 	printf("✅aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
	// 	printf("✅curr: %lld\n", (long long)s_a.head);
	// 	printf("✅value: %d\n", s_a.head->value);
	// 	printf("✅prev: %lld\n", (long long)s_a.head->prev);
	// 	printf("✅next: %lld\n", (long long)s_a.head->next);
	// 	s_a.head = s_a.head->next;
	// }
	// printf("✅==========================================\n");
	// printf("✅bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb\n");
	// printf("✅curr: %lld\n", (long long)s_b.tail);
	// printf("✅value: %d\n", s_b.tail->value);
	// printf("✅prev: %lld\n", (long long)s_b.tail->prev);
	// printf("✅next: %lld\n", (long long)s_b.tail->next);
	while (s_b.count--)
	{
		printf("✅==========================================\n");
		printf("✅curr: %lld\n", (long long)s_b.head);
		printf("✅value: %d\n", s_b.head->value);
		printf("✅prev: %lld\n", (long long)s_b.head->prev);
		printf("✅next: %lld\n", (long long)s_b.head->next);
		s_b.head = s_b.head->next;
	}

	return (0);
}
