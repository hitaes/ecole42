/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:33:23 by taeskim           #+#    #+#             */
/*   Updated: 2021/08/27 17:25:22 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

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

typedef struct candidate
{
	int		cost;
	int		place;
	t_node	*result;
}	t_candidate;

// shared
// utils
int			ft_get_conditional_num(t_stack *to, char c);
int			ft_get_index(t_stack *stk, int v);
int			ft_get_place(t_stack *to, int v, char direction);
int			ft_best_future(t_stack *s_a, t_stack *s_b, int place, int v);
void		*replace(char **out, char *src);
char		**parser_input(int argc, char **argv, int the_number_of_el, char c);
int			ft_get_count(int argc, char **argv, char c);
void		ft_t_stack_init(t_stack *u_stack);
void		ft_append_t_node(t_stack *s_a, t_node *new_node);
void		ft_remove_t_node(t_stack *stk);
t_node		*ft_export_t_node(t_node *n);
void		ft_free_stack(t_stack *stk, int i);
void		ft_error_disposal(void);

// libft
int			ft_isdigit(char c);
long long	ft_atoi(const char *src);
int			ft_strlen(char *s);
void		*ft_memset(void *b, int c, int len);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(char *s);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_get_next_line(int fd, char **line);

//	instructions
void		pb(t_stack *from, t_stack *to);
void		pa(t_stack *from, t_stack *to);
void		pp(t_stack *from, t_stack *to);
void		sa(t_stack *stk);
void		sb(t_stack *stk);
void		ss(t_stack *l_stk, t_stack *r_stk);
void		ra(t_stack *stk);
void		rb(t_stack *stk);
void		rr(t_stack *l_stk, t_stack *r_stk);
void		rra(t_stack *stk);
void		rrb(t_stack *stk);
void		rrr(t_stack *l_stk, t_stack *r_stk);

// validators
int			*validator(int count, char **v_str, char c);
int			validator_num(char *s, char c);
int			validator_int(char *s);
void		validator_duplicate(int count, int *v_nums);
void		validator_sorting(int count, int *v_nums);
void		t_node_setter(t_stack *s_a, int the_number_of_els, int *v_nums);

#endif
