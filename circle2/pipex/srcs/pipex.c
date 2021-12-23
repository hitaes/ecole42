/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:59:49 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/24 02:12:27 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_all(t_arg *t)
{
	int	i;

	i = 0;
	while (t->path[i])
	{
		if (t->path[i])
			free_p(t->path[i]);
		i++;
	}
	if (t->path)
		free_p(t->path);
	if (t->command)
		free_p(t->command);
}

void	error_disposal(t_arg *t, char *s, int i)
{
	ft_putstr_fd(s, i);
	free_all(t);
	exit(1);
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
