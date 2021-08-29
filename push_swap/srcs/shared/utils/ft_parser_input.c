/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 01:22:24 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/29 22:37:55 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

char	*ft_slicer(t_stack *stk, char **str, int *j, int *c_p)
{
	char	*tmp;

	tmp = ft_strdup(*str);
	if (!(tmp))
		ft_free(stk, STDERR_FILENO);
	tmp[*j] = 0;
	*str = *str + *j;
	*j = -1;
	*c_p = 0;
	return (tmp);
}

void	parser_input(t_stack *stk, char **argv, int the_number_of_els, char c)
{
	int		i;
	int		j;
	int		*k;
	int		c_p;

	i = 0;
	j = -1;
	k = &(stk->v_str_count);
	c_p = 0;
	stk->v_str = ft_calloc(the_number_of_els, sizeof(char *));
	while (++i < the_number_of_els + 1)
	{
		while (argv[i][++j])
		{
			if (argv[i][j] != c)
				c_p = 1;
			else if (c_p)
				stk->v_str[++(*k)] = ft_slicer(stk, &(argv[i]), &j, &c_p);
		}
		if (c_p)
			stk->v_str[++(*k)] = ft_slicer(stk, &(argv[i]), &j, &c_p);
		j = -1;
	}
}
