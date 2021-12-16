/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:59:49 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/17 01:31:13 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
}
