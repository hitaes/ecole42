/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:27:43 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/23 10:11:48 by pacman           ###   ########.fr       */
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
	// t->heredoc = 
	// x->limiter = argv[1];
	// x->tmp = "/tmp/.heredoc";
}

void	arg_init(t_arg *t, char **envp, char **argv, int argc)
{
	int	i;

	i = 0;
	t_arg_init(t);
	t->envp = envp;
	t->pipe_count = argc - 3;
	while (*envp && ft_strncmp(*envp, "PATH", 4))
		++envp;
	t->count = char_frequency(*envp, ':');
	t->path = (char **)malloc(sizeof(char *) * t->count + 1);
	if (t->path == NULL)
		ft_putstr_fd("Error : [t->Path: Malloc Error]\n", STDERR_FILENO);
	str_slicer(t, *envp, t->count);
	t->command = (char **)malloc(sizeof(char *) * argc);
	if (!t->command)
		ft_putstr_fd("Error : [t->command: Malloc Error]\n", STDERR_FILENO);
	while (i < argc)
	{
		t->command[i] = argv[i + 1];
		i++;
	}
}
