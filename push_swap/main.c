/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:27:43 by taeskim           #+#    #+#             */
/*   Updated: 2021/08/13 17:56:07 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_sorting(stack *s_a, stack *s_b)
{
	int tmp_sa;
	int tmp_sb;
	int the_number_of_els;

	tmp_sa = s_a->count;
	tmp_sb = s_b->count;
	the_number_of_els = 0;
	printf("==========================================\n");
	printf("s_a           s_b\n");
	the_number_of_els = s_a->count >= s_b->count ? s_a->count : s_b->count;
	while (the_number_of_els--)
	{
		printf("%d            %d\n", s_a->count ? s_a->head->value : 0, s_b->count ? s_b->head->value : 0);
		if (s_a->count)
		{
			s_a->count--;
			s_a->head = s_a->head->next;
		}
		if (s_b->count)
		{
			s_b->count--;
			s_b->head = s_b->head->next;
		}
	}
	printf("==========================================\n");
	s_a->count = tmp_sa;
	s_b->count = tmp_sb;
}

int main(int argc, char **argv)
{
	stack s_a;
	stack s_b;
	int the_number_of_els;
	int *v_nums;
	char **v_strs;
	char c;
	node *tmp_node;

	int i;

	i = -1;

	c = ' ';
	tmp_node = 0;
	ft_stack_init(&s_a);
	ft_stack_init(&s_b);
	the_number_of_els = ft_get_count(argc, argv, c);
	v_strs = parser_input(argc, argv, the_number_of_els, c);
	v_nums = validator(the_number_of_els, v_strs, c);
	node_setter(&s_a, the_number_of_els, v_nums);
	ft_sorting(&s_a, &s_b);

	// print_sorting(&s_a, &s_b);

	// while (s_a.count)
	// {
	// 	tmp_node = s_a.tail->prev;
	// 	free(s_a.tail);
	// 	s_a.tail = tmp_node;
	// 	s_a.count--;
	// }
	// free(v_strs);
	// v_strs = 0;
	// free(v_nums);
	// v_nums = 0;

	return (0);
}
