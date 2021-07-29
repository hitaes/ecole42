/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:27:43 by taeskim           #+#    #+#             */
/*   Updated: 2021/07/30 00:56:41 by pac-man          ###   ########.fr       */
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
	ft_sorting(&s_a, &s_b);
	printf("==========================================\n");
	printf("s_a           s_b\n");
	// 두개의 값을 비교해서 더 큰 것을 기준으로 출력
	the_number_of_els = s_a.count >= s_b.count ? s_a.count : s_b.count;
	while (the_number_of_els--)
	{
		printf("%d            %d\n", s_a.head ? s_a.head->value : 0, s_b.head ? s_b.head->value : 0);
		// printf("✅curr: %lld\n", (long long)s_a.head);
		// printf("✅value: %lld\n", (long long)s_a.head->value);
		// printf("✅prev: %lld\n", (long long)s_a.head->prev);
		// printf("✅next: %lld\n", (long long)s_a.head->next);
		if (s_a.head)
			s_a.head = s_a.head->next;
		if (s_b.head)
			s_b.head = s_b.head->next;
	}
	printf("==========================================\n");
	// printf("✅==========================================\n");
	// printf("✅curr: %lld\n", (long long)s_b.tail);
	// printf("✅value: %d\n", s_b.tail->value);
	// printf("✅prev: %lld\n", (long long)s_b.tail->prev);
	// printf("✅next: %lld\n", (long long)s_b.tail->next);
	// while (s_b.count--)
	// {
	// 	printf("✅==========================================\n");
	// 	printf("✅curr: %lld\n", (long long)s_b.head);
	// 	printf("✅value: %d\n", s_b.head->value);
	// 	printf("✅prev: %lld\n", (long long)s_b.head->prev);
	// 	printf("✅next: %lld\n", (long long)s_b.head->next);
	// 	s_b.head = s_b.head->next;
	// }

	return (0);
}
