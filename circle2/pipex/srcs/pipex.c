/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeskim <taeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:59:49 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/22 11:09:56 by taeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_arg	t;

	// if (argc != 5)
	// 	return (1);
	t_arg_init(&t);
	arg_init(&t, envp, argv, argc - 1);
	pipe_process(&t);
	// int i = 0;<
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
	return (0);
}
