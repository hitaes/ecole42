/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 02:14:41 by pacman            #+#    #+#             */
/*   Updated: 2021/12/23 22:47:02 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	child_proc(t_arg *t, int i)
{
	if (i == 0)
		set_pipe_for_infile(t);
	else if (i == t->pipe_count)
		set_pipe_for_outfile(t, i);
	else
		set_pipe_for_middle(t, i);
	exec_cmd(t, i);
}

void	parent_prc(t_arg *t, int i, int pid)
{
	int		status;

	if (i == 0)
		close(t->p1[1]);
	else if (i % 2)
		close(t->p2[1]);
	else if (!(i % 2))
		close(t->p1[1]);
	else
	{
		if (i % 2)
		{
			close(t->p1[0]);
			close(t->p2[1]);
		}
		else
		{
			close(t->p1[1]);
			close(t->p2[0]);
		}
	}
	waitpid(pid, &status, 0);
}

void	pipe_process(t_arg *t)
{
	int	i;
	int	pid;

	i = 0;
	while (i < t->pipe_count + 1)
	{
		if (i % 2)
		{
			if (pipe(t->p2) == -1)
				error_disposal(t, "Error: pipe\n", STDIN_FILENO);
		}
		else
			if (pipe(t->p1) == -1)
				error_disposal(t, "Error: pipe\n", STDIN_FILENO);
		pid = fork();
		if (pid == -1)
			error_disposal(t, "Error: fork\n", STDIN_FILENO);
		else if (pid == 0)
			child_proc(t, i);
		else
			parent_prc(t, i, pid);
		i++;
	}
}
