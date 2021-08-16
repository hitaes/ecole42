/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:44 by taeskim           #+#    #+#             */
/*   Updated: 2021/08/16 15:32:51 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "./libft/libft.h"

typedef struct node
{
	int value;
	struct node *prev;
	struct node *next;
} node;

typedef struct
{
	int count;
	int s_index;
	int s_count;
	node *head;
	node *tail;
} stack;

typedef struct
{
	int index;
	int count;
} foundation;

void validator_sign(char *str);
char **parser_input(int argc, char **argv, int the_number_of_el, char c);
// void ft_clean(void *ptr);
// utils
int ft_get_count(int argc, char **argv, char c);
void ft_stack_init(stack *u_stack);
void ft_append_node(stack *s_a, node *new_node);
void ft_remove_node(stack *stk);
node *ft_export_node(node *n);
// validators
int *validator(int count, char **v_str, char c);
int validator_num(char *s, char c);
int validator_int(char *s);
void validator_duplicate(int count, int *v_nums);
void validator_sorting(int count, int *v_nums);
void node_setter(stack *s_a, int the_number_of_els, int *v_nums);
// instructions
void pb(stack *from, stack *to);
void pa(stack *from, stack *to);
void pp(stack *from, stack *to);
void sa(stack *stk);
void sb(stack *stk);
void ss(stack *l_stk, stack *r_stk);
void ra(stack *stk);
void rb(stack *stk);
void rr(stack *l_stk, stack *r_stk);
void rra(stack *stk);
void rrb(stack *stk);
void rrr(stack *l_stk, stack *r_stk);
// sorting
void ft_sorting(stack *s_a, stack *s_b);
void ft_sorting_two(stack *s_a);
void ft_sorting_three(stack *s_a);
void ft_sorting_five(stack *s_a, stack *s_b);
void ft_sorting_all(stack *s_a, stack *s_b);
int ft_get_the_smallest_num(stack *s_a);
int ft_get_place(stack *s_a, int v);
void ft_insert_el(stack *s_a, stack *s_b, int place, int v);
int ft_best_future(stack *s_a, stack *s_b, int place, int v);
void ft_agamotto_eye(stack *s_a, stack *s_b);
// sorting util
int ft_get_index(stack *stk, int v);

#endif
