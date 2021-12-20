/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:27:43 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/20 17:27:12 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	t_arg_init(t_arg *t)
{
	t->command = 0;
	t->count = 0;
	t->path = 0;
	t->pipe_odd[0] = -1;
	t->pipe_odd[1] = -1;
	t->pipe_even[0] = -1;
	t->pipe_even[1] = -1;
	t->max_index = 0;
	t->curr_index = 0;
	t->envp = 0;
}

void	arg_init(t_arg *t, char **envp, char **argv, int argc)
{
	int	i;

	i = 0;
	t->envp = envp;
	while (*envp && ft_strncmp(*envp, "PATH", 4))
		++envp;
	t->count = char_frequency(*envp, ':');
	t->path = (char **)malloc(sizeof(char *) * t->count + 1);
	t->max_index = argc - 1;
	if (t->path == NULL)
		ft_putstr_fd("Error : [t->Path: Malloc Error]\n", STDERR_FILENO);
	str_slicer(t, *envp);
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
