/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:27:43 by taeskim           #+#    #+#             */
/*   Updated: 2021/07/08 20:15:01 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void node_setter(node_container *nc, int count , char **argv)
{
	int i;

	i = -1;
	while (count > ++i)
	{
		if (i == 0)
		{
			nc->node_box[i].previous = &(nc->node_box[count - 1]);
			nc->node_box[i].next = &(nc->node_box[i + 1]);
		}
		else if (i == count - 1)
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
	node_container* nc = (node_container *)malloc(sizeof(node_container) + (argc - 1) * sizeof(int));
	nc->count = argc - 1;
	if (!nc)
		exit(1);
	else
		node_setter(nc, nc->count, argv);
	// while (nc->count > ++i)
	// {
	// 	printf("==================================================\n");
	// 	printf("✅previous address : %p\n", nc->node_box[i].previous);
	// 	printf("✅current address : %p\n", &(nc->node_box[i]));
	// 	printf("✅next address : %p\n", nc->node_box[i].next);
	// 	printf("✅value : %d\n", nc->node_box[i].value);
	// }

	free(nc);
	nc = 0;
	return (0);
}
