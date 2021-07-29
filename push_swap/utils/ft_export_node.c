/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:21:55 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/30 00:22:13 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

node *ft_export_node(node *n)
{
	node *tmp;

	tmp = (node *)malloc(sizeof(node));
	if (!(tmp))
		return (NULL);
	tmp->value = n->value;
	tmp->next = 0;
	tmp->prev = 0;
	free(n);
	n = 0;
	return (tmp);
}
