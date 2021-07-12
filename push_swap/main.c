/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:27:43 by taeskim           #+#    #+#             */
/*   Updated: 2021/07/12 18:06:31 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

// 정렬 되었는지 확인하는 함수

/*✅ 정렬 되었는지 확인하는 함수
0을 반환하면 false
1을 반환하면 true
*/
/*✅ 동일한 eleement가 들어온 경우를 Validation하는 함수를 어디다 놓을 것인가를 고민해야 할듯*/

int	sorted_checker(node_container *nc)
{
	int i;
	int j;
	int sorting_count;

	i = -1;
	j = 0;
	sorting_count = 0;
	while (++i < nc->count)
	{
		while (++j < nc->count)
			if (nc->node_box[i].value == nc->node_box[j].value)
				exit(1);
		if (nc->node_box[i].value < nc->node_box[i + 1].value)
			sorting_count += 1;
	}
	return (sorting_count == nc->count - 1? 1 : 0);
}

void node_setter(node_container *nc, char **argv)
{
	int i;

	i = -1;
	while (nc->count > ++i)
	{
		if (i == 0)
		{
			nc->node_box[i].previous = &(nc->node_box[nc->count - 1]);
			nc->node_box[i].next = &(nc->node_box[i + 1]);
		}
		else if (i == nc->count - 1)
		{
			nc->node_box[i].previous = &(nc->node_box[i - 1]);
			nc->node_box[i].next = &(nc->node_box[0]);
		}
		else
		{
			nc->node_box[i].previous = &(nc->node_box[i - 1]);
			nc->node_box[i].next = &(nc->node_box[i + 1]);
		}
		nc->node_box[i].value = validator_num(argv[i + 1]);
	}
}

int	main(int argc, char **argv)
{
	int i;

	i = -1;
	node_container* nc = (node_container *)malloc(sizeof(node_container) + (argc - 1) * sizeof(node));
	nc->count = argc - 1;
	if (!nc)
		exit(1);
	else
		node_setter(nc, argv);
	if (sorted_checker(nc))
		printf("✅this is sorted\n");

	free(nc);
	nc = 0;
	return (0);
}
