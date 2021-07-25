/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:44 by taeskim           #+#    #+#             */
/*   Updated: 2021/07/25 17:28:18 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct	node
{
	int			value;
	struct node *prev;
	struct node *next;
}				node;

typedef struct
{
	int			count;
	node 		*head;
	node 		*tail;
}				stack;

void validator_sign(char *str);
char **parser_input(int argc, char **argv);
// char **parser_input(int argc, int count, char **argv);
void ft_clean(void *ptr);
int ft_get_count(int argc, char **argv);
int *validator(int count, char **v_str);
int	validator_num(char *s);
int	validator_int(char *s);
void validator_duplicate(int count, int *v_nums);
void validator_sorting(int count, int *v_nums);
stack *node_setter(stack *s_a, int count, int *v_nums);

#endif
