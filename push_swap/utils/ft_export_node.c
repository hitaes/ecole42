/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:21:55 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/25 14:23:16 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_export_t_node(t_node *n)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!(tmp))
		return (NULL);
	tmp->value = n->value;
	tmp->next = 0;
	tmp->prev = 0;
	if (n)
	{
		free(n);
		n = 0;
	}
	return (tmp);
}
