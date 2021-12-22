/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:20:07 by pacman            #+#    #+#             */
/*   Updated: 2021/12/23 02:40:54 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	set_pipe_for_infile(t_arg *t)
{
	int		fd;

	fd = file_open(t->command[0], O_RDONLY);
	if (dup2(fd, STDIN_FILENO) == -1)
		printf("Error dup2\n");
	close(fd);
	if (dup2(t->p1[1], STDOUT_FILENO) == -1)
		printf("Error dup2\n");
}

void	set_pipe_for_outfile(t_arg *t, int i)
{
	int	fd;

	if (i % 2)
	{
		if (dup2(t->p1[0], STDIN_FILENO) == -1)
			printf("error pipe p1\n");
		close(t->p1[0]);
	}
	else
	{
		if (dup2(t->p2[0], STDIN_FILENO) == -1)
			printf("Error dup2\n");
		close(t->p2[0]);
	}
	fd = file_open(t->command[t->pipe_count + 2], O_WRONLY | O_CREAT | O_TRUNC);
	if (dup2(fd, STDOUT_FILENO) == -1)
		printf("Error dup2\n");
	close(fd);
}

void	set_pipe_for_middle(t_arg *t, int i)
{
	if (i % 2)
	{
		if (dup2(t->p1[0], STDIN_FILENO) == -1)
			printf("error pipe p1\n");
		close(t->p1[0]);
		if (dup2(t->p2[1], STDOUT_FILENO) == -1)
			printf("error pipe p1\n");
		close(t->p2[1]);
	}
	else
	{
		if (dup2(t->p2[0], STDIN_FILENO) == -1)
			printf("Error dup2\n");
		close(t->p2[0]);
		if (dup2(t->p1[1], STDOUT_FILENO) == -1)
			printf("Error dup2\n");
		close(t->p1[1]);
	}
}

// void	infile_to_pipe(t_arg *t, int i)
// {
// 	set_pipe_for_infile(t);
// 	exec_cmd(t, i);
// }

// void	outfile_from_pipe(t_arg *t, int i)
// {
// 	set_pipe_for_outfile(t, i);
// 	exec_cmd(t, i);
// }
