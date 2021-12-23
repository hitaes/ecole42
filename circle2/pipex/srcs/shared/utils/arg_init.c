/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:27:43 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/23 22:46:27 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	t_arg_init(t_arg *t)
{
	t->command = 0;
	t->pipe_count = 0;
	t->path = 0;
	t->envp = 0;
	t->p1[0] = -1;
	t->p1[1] = -1;
	t->p2[0] = -1;
	t->p2[1] = -1;
}

void	arg_init(t_arg *t, char **envp, char **argv, int argc)
{
	int		i;
	char	**tmp;

	i = 0;
	t_arg_init(t);
	t->envp = envp;
	t->pipe_count = argc - 3;
	while (*envp && ft_strncmp(*envp, "PATH", 4))
		++envp;
	t->path = ft_split(*envp, ':');
	tmp = ft_split(t->path[0], '=');
	free_p(t->path[0]);
	t->path[0] = tmp[1];
	free_p(tmp[0]);
	free_p(tmp);
	t->command = (char **)malloc(sizeof(char *) * argc + 1);
	if (!t->command)
		error_disposal(t, "Error: malloc\n", STDIN_FILENO);
	while (i < argc)
	{
		t->command[i] = argv[i + 1];
		i++;
	}
}
