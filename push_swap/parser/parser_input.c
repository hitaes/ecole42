/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 01:22:24 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/28 12:32:06 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char *ft_slicer(char **str, int *j, int *char_appear)
{
	char *tmp;

	tmp = ft_strdup(*str);
	tmp[*j] = 0;
	*str = *str + *j;
	*j = -1;
	*char_appear = 0;
	return (tmp);
}

char **parser_input(int argc, char **argv, int the_number_of_els, char c)
{
	int i;
	int j;
	int k;
	int char_appear;
	char **v_strs;

	i = 0;
	j = -1;
	k = -1;
	char_appear = 0;
	v_strs = ft_calloc(sizeof(char *), the_number_of_els);
	while (++i < argc)
	{
		while (argv[i][++j])
		{
			if (argv[i][j] != c)
				char_appear = 1;
			else if (char_appear)
				v_strs[++k] = ft_slicer(&(argv[i]), &j, &char_appear);
		}
		if (char_appear)
			v_strs[++k] = ft_slicer(&(argv[i]), &j, &char_appear);
		j = -1;
	}
	return (v_strs);
}
