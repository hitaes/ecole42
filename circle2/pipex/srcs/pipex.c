/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:59:49 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/16 11:05:40 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	pipe_process(t_arg *t)
{
	
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	t;

	t_arg_init(&t);
	arg_init(&t, envp, argv, argc - 1);
	pipe_process(&t);
	// int i = 0;
	// while (t.command[i])
	// {
	// 	printf("t.command%d, %s\n", i, t.command[i]);
	// 	i++;
	// }
	// i = 0;
	// while (t.path[i])
	// {
	// 	printf("t.path%d, %s\n", i, t.path[i]);
	// 	i++;
	// }
	
	(void)argc;
	(void)argv;
}
