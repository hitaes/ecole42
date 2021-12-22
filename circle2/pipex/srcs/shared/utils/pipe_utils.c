/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:20:07 by pacman            #+#    #+#             */
/*   Updated: 2021/12/23 00:32:13 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

// int	file_open(char *file, int mode)
// {
// 	int	fd;

// 	fd = open(file, mode);
// 	if (fd < 0)
// 		ft_putstr_fd("Error : [OPEN: open failed]\n", STDERR_FILENO);
// 	return (fd);
// }

// void	pipe_open(int pp[2])
// {
// 	if (pipe(pp) == -1)
// 		ft_putstr_fd("Error : [PIPE: pipe failed]\n", STDERR_FILENO);
// }

// void	command_exec(t_arg *t, int i)
// {
// 	char	*command;

// 	command = command_checker(t, i);
// 	if (!command)
// 		ft_putstr_fd("Error : [COMMAND: command is not available]\n",
// 			STDERR_FILENO);
// 	execve(command, &t->command[i], 0);
// }

// void	infile_to_pipe(t_arg *t, int i)
// {
// 	int		fd;

// 	fd = file_open(t->command[i], O_RDONLY);
// 	if (dup2(fd, STDIN_FILENO) == -1)
// 		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
// 	close(fd);
// }

// void	outfile_to_pipe(t_arg *t, int i)
// {
// 	int		fd;

// 	fd = file_open(t->command[i], O_CREAT);
// 	// if (i % 2)
// 	// {
// 	// 	close(t->p1[1]);
// 	// 	if (dup2(t->p1[0], STDIN_FILENO) == -1)
// 	// 		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
// 	// }
// 	// else
// 	// {
// 	if (dup2(t->p2[0], STDIN_FILENO) == -1)
// 		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
// 	// }
// 	if (dup2(fd, STDOUT_FILENO) == -1)
// 		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
// }

// void	child_proc_pipe(t_arg *t, int i)
// {
// 	// if (i % 2)
// 	// {
// 	if (i == 1)
// 	{
// 		if (dup2(t->p1[1], STDOUT_FILENO) == -1)
// 			ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
// 		close(t->p1[1]);
// 	}
// 	else if (i == 2)
// 	{
// 		if (dup2(t->p1[0], STDIN_FILENO) == -1)
// 			ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
// 		// close(t->p1[0]);
// 		if (dup2(t->p2[1], STDOUT_FILENO) == -1)
// 			ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
// 		// close(t->p2[1]);
// 	}
// 	// else if (i == 2)
// 	// {
// 	// 	if (dup2(t->p2[0], STDIN_FILENO) == -1)
// 	// 		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
// 	// 	close(t->p2[0]);
// 	// }
// 	// }
// 	// else
// 	// {
// 	// 	if (dup2(t->p1[0], STDIN_FILENO) == -1)
// 	// 		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
// 	// 	close(t->p1[0]);
// 	// 	if (dup2(t->p2[1], STDOUT_FILENO) == -1)
// 	// 		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
// 	// 	close(t->p2[1]);
// 	// }
// }

// void	command_process(t_arg *t, int i)
// {
// 	int		status;
// 	int		fd;
// 	int		pid;

// 	status = 0;
// 	pid = fork();
// 	if (pid == -1)
// 		ft_putstr_fd("Error : [fork: fork failed]\n", STDERR_FILENO);
// 	if (i == 0)
// 	{	
// 		fd = open(t->command[0], O_RDONLY);
// 		if (fd == -1)
// 			printf("open Error\n");
// 		if (dup2(fd, STDIN_FILENO) == -1)
// 			printf("Dup2 Error\n");
// 		if (dup2(t->p1[1], STDOUT_FILENO) == -1)
// 			printf("Dup2 Error\n");
// 	}
// 	if (pid == 0)
// 	{
// 		printf("child process\n");
// 		// child_proc_pipe(t, i);
// 		command_exec(t, 1);
// 	}
// 	else
// 	{
// 		printf("parent process\n");
// 		// if (i == 0)
// 		// 	close(t->p2[1]);
// 		// else
// 		// {
// 		// 	if (i % 2)
// 		// 	{
// 		// 		close(t->p2[0]);
// 		// 		close(t->p1[1]);
// 		// 	}
// 		// 	else
// 		// 	{
// 		// 		close(t->p2[1]);
// 		// 		close(t->p1[0]);
// 		// 	}
// 		// }
// 		waitpid(pid, &status, 0);
// 	}
// }

void	child_proc(t_arg *t, int i)
{
	int		fd;
	char	*cmd;

	printf("%d\n", i);
	if (i == 0)
	{
		fd = open(t->command[i], O_RDONLY);
		if (fd == -1)
			printf("Error open\n");
		if (dup2(fd, STDIN_FILENO) == -1)
			printf("Error dup2\n");
		close(fd);
		if (dup2(t->p1[1], STDOUT_FILENO) == -1)
			printf("Error dup2\n");
		cmd = command_checker(t, i + 1);
		if (!cmd)
			printf("cmd is null");
		execve(cmd, &t->command[i + 1], t->envp);
		// execve(cmd, &(t->command[i + 1]), NULL);
	}
	else if (i == 1) // pipe의 갯수로 하면 됨.
	{
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
		fd = open(t->command[3], O_WRONLY | O_CREAT | O_TRUNC);
		if (fd == -1)
			printf("Error open\n");
		if (dup2(fd, STDOUT_FILENO) == -1)
			printf("Error dup2\n");
		close(fd);
		cmd = command_checker(t, i + 1);
		if (!cmd)
			printf("cmd is null");
		execve(cmd, &t->command[i + 1], t->envp);
	}
	else
	{
		if (i % 2)
		{
			if (dup2(t->p2[0], STDIN_FILENO) == -1)
				printf("Error dup2\n");
			close(t->p2[0]);
			if (dup2(t->p1[1], STDOUT_FILENO) == -1)
				printf("Error dup2\n");
			close(t->p1[0]);
		}
		else
		{
			if (dup2(t->p1[0], STDIN_FILENO) == -1)
				printf("error pipe p1\n");
			close(t->p1[0]);
			if (dup2(t->p2[0], STDIN_FILENO) == -1)
				printf("error pipe p1\n");
			close(t->p2[0]);
		}
		cmd = command_checker(t, i + 1);
		if (!cmd)
			printf("cmd is null");
		execve(cmd, &t->command[i + 1], t->envp);
	}
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
	while (i < 2) // 파이프의 갯수 + 1로 하면 됨
	{
		printf("main called\n");
		if (i % 2)
		{
			if (pipe(t->p2) == -1)
				printf("error pipe p2\n");
		}
		else
			if (pipe(t->p1) == -1)
				printf("error pipe p1\n");
		pid = fork();
		if (pid == -1)
			ft_putstr_fd("Error : [fork: fork failed]\n", STDERR_FILENO);
		else if (pid == 0)
			child_proc(t, i);
		else
			parent_prc(t, i, pid);
		i++;
	}
}
