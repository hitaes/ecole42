/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 01:17:56 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/30 01:18:02 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_do_checker(t_stack *s_a, t_stack *s_b, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		return (pa(s_b, s_a, STDIN_FILENO));
	else if (ft_strcmp(line, "pb") == 0)
		return (pb(s_a, s_b, STDIN_FILENO));
	else if (ft_strcmp(line, "sa") == 0)
		return (sa(s_a, STDIN_FILENO));
	else if (ft_strcmp(line, "sb") == 0)
		return (sb(s_b, STDIN_FILENO));
	else if (ft_strcmp(line, "ra") == 0)
		return (ra(s_a, STDIN_FILENO));
	else if (ft_strcmp(line, "rb") == 0)
		return (rb(s_b, STDIN_FILENO));
	else if (ft_strcmp(line, "rra") == 0)
		return (rra(s_a, STDIN_FILENO));
	else if (ft_strcmp(line, "rrb") == 0)
		return (rrb(s_b, STDIN_FILENO));
	else if (ft_strcmp(line, "ss") == 0)
		return (ss(s_a, s_b, STDIN_FILENO));
	else if (ft_strcmp(line, "rr") == 0)
		return (rr(s_a, s_b, STDIN_FILENO));
	else if (ft_strcmp(line, "rrr") == 0)
		return (rrr(s_a, s_b, STDIN_FILENO));
	else if (line[0] == 0)
		return (1);
	return (0);
}

void	ft_gnl_check(t_stack *s_a, t_stack *s_b)
{
	int		ret;
	char	*line;

	while (1)
	{
		ret = ft_get_next_line(STDIN_FILENO, &line);
		if (ret == -1 || !ft_do_checker(s_a, s_b, line))
		{
			ft_free(s_a, STDERR_FILENO);
			ft_free(s_b, STDERR_FILENO);
		}
		free(line);
		line = 0;
		if (!ret)
			break ;
	}
	if (validator_sorting(s_a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}
