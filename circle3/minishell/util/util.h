/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:31:01 by sgang             #+#    #+#             */
/*   Updated: 2021/12/18 20:10:52 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include <stdlib.h>

# define RET_ERROR -1

typedef struct s_snode	t_snode;
typedef struct s_slist	t_slist;

typedef struct s_dnode	t_dnode;
typedef struct s_dlist	t_dlist;

struct				s_snode
{
	void			*data;
	struct s_snode	*next;
};

struct				s_slist
{
	struct s_snode	*head;
	struct s_snode	*tail;
};

struct				s_dnode
{
	void			*data;
	struct s_dnode	*prev;
	struct s_dnode	*next;
};

struct				s_dlist
{
	struct s_dnode	*head;
	struct s_dnode	*tail;
};

// algorithms
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_abs(int a);
void	ft_swap(void *a, void *b, int len);

// stdlib
void	ft_exit(char *msg);
int		ft_atoi(char **num, int sign);
void	*ft_calloc(int number, int size, char ch);

// string
void	ft_memcpy(char *dest, char *src, int sz);
int		ft_strlen(char *str);
void	ft_memset(char *dest, int size, char ch);
int		ft_strcmp(char *s1, char *s2);

// print
void	ft_putnum(int num);
void	ft_putchar(char ch);
void	ft_puts(char *msg);
void	ft_puts_fd(char *msg, int fd);

// single_list
void	slist_ppback(t_slist *list, void *data);
t_slist	*slist_new_list();
void	slist_pback(t_snode **slist, void *data);

// double_list
t_dnode	*dlist_new_node(void *data);
t_dlist	*dlist_new_list();
void	dlist_pback(t_dlist *list, void *data);
void	dlist_pfront(t_dlist *list, void *data);
void	dlist_init(t_dlist *list);

// list_destroy
void	dlist_delete_node(t_dnode *node);
void	list_double_destroy(t_dlist *list);

// ctype
int		ft_isspace(char ch);
int		ft_isdigit(char ch);
int		ft_isalpha(char ch);
int		ft_sign(char ch);

#endif