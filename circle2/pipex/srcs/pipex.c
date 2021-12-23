/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:59:49 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/23 17:27:10 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_all(t_arg *t)
{
	int	i;

	i = 0;
	while (t->path[i])
	{
		free_p(t->path[i]);
		i++;
	}
	free_p(t->path[i]);
	free_p(t->command);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	t;

	if (argc < 5)
		return (1);
	arg_init(&t, envp, argv, argc - 1);
	pipe_process(&t);
	free_all(&t);
	return (0);
}
