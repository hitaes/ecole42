/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:20:07 by pacman            #+#    #+#             */
/*   Updated: 2021/12/17 01:45:31 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

int	file_open(t_arg *t)
{
	int	fd;

	fd = open(t->command[0], O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error : [OPEN: open failed]\n", STDERR_FILENO);
	return (fd);
}

void	pipe_open(int pp[2])
{
	if (pipe(pp) == -1)
		ft_putstr_fd("Error : [PIPE: pipe failed]\n", STDERR_FILENO);
}

void	infile_to_pipe(t_arg *t)
{
	int	fd;

	pipe_open(t->pipe_last);
	fd = file_open(t);
	if (dup2(fd, t->pipe_last[1]) == -1)
		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
	close(fd);
}

void	command_process(t_arg *t)
{
	pid_t	pid;
	int		status;

	pid = fork();
	status = 0;
	if (pid == -1)
		ft_putstr_fd("Error : [fork: fork failed]\n", STDERR_FILENO);
	if (pid == 0)
	{
		
	}
	else
	{
		waitpid(pid, &status, 0);
		// if (!WIFEXITED(stat))
		// 	perror(strerror(errno));
	}
}

void	pipe_process(t_arg *t)
{
	int	i;

	i = 0;
	infile_to_pipe(t);
	while (t->command[i])
	{
		command_process(t);
		i++;
	}
	outfile_to_pipe(t);
}
