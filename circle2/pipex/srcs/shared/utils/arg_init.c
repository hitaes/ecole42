/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:27:43 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/17 01:26:46 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	t_arg_init(t_arg *t)
{
	t->command = 0;
	t->count = 0;
	t->path = 0;
	t->pipe[0] = -1;
	t->pipe[1] = -1;
	t->pipe_last[0] = -1;
	t->pipe_last[1] = -1;
}

void	arg_init(t_arg *t, char **envp, char **argv, int argc)
{
	int	i;

	i = 0;
	while (*envp && ft_strncmp(*envp, "PATH", 4))
		++envp;
	t->count = char_frequency(*envp, ':');
	t->path = (char **)malloc(sizeof(char *) * t->count + 1);
	if (t->path == NULL)
		ft_putstr_fd("Error : [t->Path: Malloc Error]\n", STDERR_FILENO);
	str_slicer(t, *envp);
	t->path[t->count] = 0;
	t->command = (char **)malloc(sizeof(char *) * argc + 1);
	if (!t->command)
		ft_putstr_fd("Error : [t->command: Malloc Error]\n", STDERR_FILENO);
	while (i < argc)
	{
		t->command[i] = argv[i + 1];
		i++;
	}
	t->command[argc] = 0;
}
