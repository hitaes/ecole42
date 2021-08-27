/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:39:58 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/27 17:51:04 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "stdio.h"

void	do_order_checker(t_stack *s_a, t_stack *s_b, char *str)
{
	if (ft_strcmp(str, "pa") == 0)
		pa(s_b, s_a);
	else if (ft_strcmp(str, "pb") == 0)
		pb(s_a, s_b);
	else if (ft_strcmp(str, "sa") == 0)
		sa(s_a);
	else if (ft_strcmp(str, "sb") == 0)
		sb(s_b);
	else if (ft_strcmp(str, "ra") == 0)
		ra(s_a);
	else if (ft_strcmp(str, "rb") == 0)
		rb(s_b);
	else if (ft_strcmp(str, "rra") == 0)
		rra(s_a);
	else if (ft_strcmp(str, "rrb") == 0)
		rrb(s_b);
	else if (ft_strcmp(str, "ss") == 0)
		ss(s_a, s_b);
	else if (ft_strcmp(str, "rr") == 0)
		rr(s_a, s_b);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(s_a, s_b);
	else
		ft_free_stack(s_a, 1);
}

void	ft_strfree(char *str)
{
	if (str == 0)
		return ;
	free(str);
	str = 0;
}

int	main(int argc, char **argv)
{
	t_stack	s_a;
	t_stack	s_b;
	int		ret;
	char	*line;

	line = 0;
	ft_t_stack_init(&s_a);
	ft_t_stack_init(&s_b);
	if (argc <= 1)
		exit(0);
	t_node_setter(&s_a, ft_get_count(argc, argv, ' '),
		validator(ft_get_count(argc, argv, ' '),
			parser_input(argc, argv, ft_get_count(argc, argv, ' '), ' '), ' '));
	ret = ft_get_next_line(0, &line);
	while (ret > 0)
	{
		do_order_checker(&s_a, &s_b, line);
		ft_strfree(line);
		ret = ft_get_next_line(0, &line);
	}
	if (check_sort(&s_a) == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	ft_free_stack(&s_a, 0);
}
