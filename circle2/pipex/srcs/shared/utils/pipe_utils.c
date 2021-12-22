/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:20:07 by pacman            #+#    #+#             */
/*   Updated: 2021/12/22 16:24:23 by pacman           ###   ########.fr       */
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

void	command_exec(t_arg *t, int i)
{
	char	*command;

	command = command_checker(t, i);
	if (!command)
		ft_putstr_fd("Error : [COMMAND: command is not available]\n",
			STDERR_FILENO);
	printf("path: %s, cmd: %s\n", command, t->command[i]);
	execve(command, &t->command[i], 0);
}

void	infile_to_pipe(t_arg *t, int i)
{
	int		fd;

	fd = file_open(t->command[i], O_RDONLY);
	if (dup2(fd, STDIN_FILENO) == -1)
		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
	close(fd);
}

void	outfile_to_pipe(t_arg *t, int i)
{
	int		fd;

	fd = file_open(t->command[i], O_CREAT);
	// if (i % 2)
	// {
	// 	close(t->p1[1]);
	// 	if (dup2(t->p1[0], STDIN_FILENO) == -1)
	// 		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
	// }
	// else
	// {
	if (dup2(t->p2[0], STDIN_FILENO) == -1)
		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
	// }
	if (dup2(fd, STDOUT_FILENO) == -1)
		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
	printf("✅Dec 22, 2021 12:35:46 PM \n");
}

void	child_proc_pipe(t_arg *t, int i)
{
	// if (i % 2)
	// {
	if (i == 1)
	{
		if (dup2(t->p1[1], STDOUT_FILENO) == -1)
			ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
		close(t->p1[1]);
	}
	else if (i == 2)
	{
		if (dup2(t->p1[0], STDIN_FILENO) == -1)
			ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
		// close(t->p1[0]);
		if (dup2(t->p2[1], STDOUT_FILENO) == -1)
			ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
		// close(t->p2[1]);
	}
	// else if (i == 2)
	// {
	// 	if (dup2(t->p2[0], STDIN_FILENO) == -1)
	// 		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
	// 	close(t->p2[0]);
	// }
	// }
	// else
	// {
	// 	if (dup2(t->p1[0], STDIN_FILENO) == -1)
	// 		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
	// 	close(t->p1[0]);
	// 	if (dup2(t->p2[1], STDOUT_FILENO) == -1)
	// 		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
	// 	close(t->p2[1]);
	// }
}

void	command_process(t_arg *t, int i)
{
	int		pid;
	int		status;

	// if (i % 2)
	if (i == 1)
		pipe_open(t->p1);
	else if (i == 2)
		pipe_open(t->p2);
	// else
	// 	pipe_open(t->p2);
	pid = fork();
	status = 0;
	if (pid == -1)
		ft_putstr_fd("Error : [fork: fork failed]\n", STDERR_FILENO);
	if (pid == 0)
	{
		child_proc_pipe(t, i);
		command_exec(t, i);
	}
	else
	{
		// if (i == 0)
		// 	close(t->p2[1]);
		// else
		// {
		// 	if (i % 2)
		// 	{
		// 		close(t->p2[0]);
		// 		close(t->p1[1]);
		// 	}
		// 	else
		// 	{
		// 		close(t->p2[1]);
		// 		close(t->p1[0]);
		// 	}
		// }
		waitpid(pid, &status, 0);
	}
}

void	pipe_process(t_arg *t)
{
	int	i;

	i = 0;
	while (t->command[i])
	{
		// 파일명 / cmd / cmd / 파일명 / NULL
		if (i % 2)
		{
			if (pipe(t->p1) == -1)
				printf("error pipe p1\n");
		}
		else
		{
			if (pipe(t->p2) == -1)
				printf("error pipe p2\n");
		}
		if (i == 0)
		{
			int		fd;
			char	*cmd;
			int		pid;

			pid = 0;
			cmd = 0;
			fd = open(t->command[0], O_RDONLY);
			if (fd == -1)
				printf("error open\n");
			if (dup2(fd, STDIN_FILENO) == -1)
				printf("error dup2\n");
			if (dup2(t->p2[1], STDOUT_FILENO) == -1)
				printf("error dup2\n");
			i++;
			pid = fork();
			if (pid)
			{
				cmd = command_checker(t, i);
				execve(cmd, &t->command[i], 0);
			}
			else
			{
				
			}
		}
		else if (i == 1)
		{
			
		}
		i++;
	// }
	// 1. infile전에 파일 디스크립터를 이용해 파이프 셋팅 해야함.
	// 2. fork()
	// 3. infile에서 열었던 파일을 표준 입력과 출력으로 연결하기
	// 3-1. 열었던 파일의 fd를 stdi에 연결시킴
	// 3-2. 
	// infile_to_pipe(t, i);
	// ++i;
	// // while (i < t->count)
	// // {
	// command_process(t, i);
	// ++i;
	// command_process(t, i);
	// ++i;
	// // }
	// outfile_to_pipe(t, i);
}
