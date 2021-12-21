/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:20:07 by pacman            #+#    #+#             */
/*   Updated: 2021/12/22 08:17:47 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

int	file_open(char *file, int mode)
{
	int	fd;

	fd = open(file, mode);
	if (fd < 0)
		ft_putstr_fd("Error : [OPEN: open failed]\n", STDERR_FILENO);
	return (fd);
}

void	pipe_open(int pp[2])
{
	if (pipe(pp) == -1)
		ft_putstr_fd("Error : [PIPE: pipe failed]\n", STDERR_FILENO);
}

void	infile_to_pipe(t_arg *t, int i)
{
	int		fd;

	fd = file_open(t->command[i], O_RDONLY);
	if (dup2(fd, STDIN_FILENO) == -1)
		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
	close(fd);
	if (dup2(t->pipe_even[1], STDOUT_FILENO) == -1)
		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
}

void	outfile_to_pipe(t_arg *t, int i)
{
	int		fd;

	fd = file_open(t->command[i], O_CREAT);
	if (i % 2)
	{
		close(t->pipe_odd[1]);
		if (dup2(t->pipe_odd[0], STDIN_FILENO) == -1)
			ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
	}
	else
	{
		close(t->pipe_even[1]);
		if (dup2(t->pipe_even[0], STDIN_FILENO) == -1)
			ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
}

void	child_process(t_arg *t, int i)
{
	char	*command;

	command = 0;
	if (i == 0)
		infile_to_pipe(t, i);
	else if (i == t->max_index - 1)
		outfile_to_pipe(t, i);
	else
	{
		if (i % 2)
		{
			if (dup2(t->pipe_even[0], STDIN_FILENO) == -1)
				ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
			close(t->pipe_even[0]);
			if (dup2(t->pipe_odd[1], STDOUT_FILENO) == -1)
				ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
			close(t->pipe_odd[1]);
		}
		else
		{
			if (dup2(t->pipe_odd[0], STDIN_FILENO) == -1)
				ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
			close(t->pipe_odd[0]);
			if (dup2(t->pipe_even[1], STDOUT_FILENO) == -1)
				ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
			close(t->pipe_even[1]);
		}	
	}
	command = command_checker(t, i);
	if (!command)
		ft_putstr_fd("Error : [COMMAND: command is not available]\n",
			STDERR_FILENO);
	printf("path: %s, cmd: %s\n", command, t->command[i]);
	execve(command, &t->command[i], 0);
}

void	command_process(t_arg *t, int i)
{
	int		pid;
	int		status;

	pid = fork();
	status = 0;
	if (pid == -1)
		ft_putstr_fd("Error : [fork: fork failed]\n", STDERR_FILENO);
	if (pid == 0)
	{
		child_process(t, i);
	}
	else
	{
		// if (i == 0)
		// 	close(t->pipe_even[1]);
		// else
		// {
		// 	if (i % 2)
		// 	{
		// 		close(t->pipe_even[0]);
		// 		close(t->pipe_odd[1]);
		// 	}
		// 	else
		// 	{
		// 		close(t->pipe_even[1]);
		// 		close(t->pipe_odd[0]);
		// 	}
		// }
		waitpid(pid, &status, 0);
	}
}

void	pipe_process(t_arg *t)
{
	int	i;

	i = 0;
	while (i < t->max_index)
	{
		if (i % 2)
			pipe_open(t->pipe_odd);
		else
			pipe_open(t->pipe_even);
		command_process(t, i);
		i++;
	}
}
