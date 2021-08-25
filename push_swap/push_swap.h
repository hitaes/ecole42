/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:44 by taeskim           #+#    #+#             */
/*   Updated: 2021/08/26 01:58:24 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct node
{
	int			value;
	struct node	*prev;
	struct node	*next;
}	t_node;

typedef struct stack
{
	int		count;
	int		s_index;
	int		s_count;
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct foundation
{
	int	index;
	int	count;
}	t_foundation;

typedef struct candidate
{
	int		cost;
	int		place;
	t_node	*result;
}	t_candidate;

// parser
char	**parser_input(int argc, char **argv, int the_number_of_el, char c);
//	utils
int		ft_get_count(int argc, char **argv, char c);
void	ft_t_stack_init(t_stack *u_stack);
void	ft_append_t_node(t_stack *s_a, t_node *new_node);
void	ft_remove_t_node(t_stack *stk);
t_node	*ft_export_t_node(t_node *n);
void	ft_free_stack(t_stack *stk);
void	ft_error_disposal(void);
//	validators
int		*validator(int count, char **v_str, char c);
int		validator_num(char *s, char c);
int		validator_int(char *s);
void	validator_duplicate(int count, int *v_nums);
void	validator_sorting(int count, int *v_nums);
void	t_node_setter(t_stack *s_a, int the_number_of_els, int *v_nums);
//	instructions
void	pb(t_stack *from, t_stack *to);
void	pa(t_stack *from, t_stack *to);
void	pp(t_stack *from, t_stack *to);
void	sa(t_stack *stk);
void	sb(t_stack *stk);
void	ss(t_stack *l_stk, t_stack *r_stk);
void	ra(t_stack *stk);
void	rb(t_stack *stk);
void	rr(t_stack *l_stk, t_stack *r_stk);
void	rra(t_stack *stk);
void	rrb(t_stack *stk);
void	rrr(t_stack *l_stk, t_stack *r_stk);
//	sorting
void	ft_sorting(t_stack *s_a, t_stack *s_b);
void	ft_sorting_two(t_stack *s_a);
void	ft_sorting_three(t_stack *s_a);
void	ft_sorting_five(t_stack *s_a, t_stack *s_b);
void	ft_sorting_all(t_stack *s_a, t_stack *s_b);
void	ft_insert_el(t_stack *s_a, t_stack *s_b, int place, int v);
//	void ft_insert_el_r(stack *to, stack *from, int place, int v);
void	ft_agamotto_eye(t_stack *to, t_stack *from, char direction, int range);
void	ft_to_base(t_stack *stk, char direction);
//	sorting util
int		ft_get_conditional_num(t_stack *to, char c);
int		ft_get_index(t_stack *stk, int v);
int		ft_get_place(t_stack *to, int v, char direction);
int		ft_best_future(t_stack *s_a, t_stack *s_b, int place, int v);

#endif
