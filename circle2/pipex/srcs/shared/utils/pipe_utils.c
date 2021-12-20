/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:20:07 by pacman            #+#    #+#             */
/*   Updated: 2021/12/20 18:27:57 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

int	file_open(t_arg *t)
{
	int	fd;

	fd = open(t->command[t->curr_index], O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error : [OPEN: open failed]\n", STDERR_FILENO);
	t->curr_index++;
	return (fd);
}

void	pipe_open(int pp[2])
{
	if (pipe(pp) == -1)
		ft_putstr_fd("Error : [PIPE: pipe failed]\n", STDERR_FILENO);
}

void	infile_to_pipe(t_arg *t)
{
	int		fd;

	pipe_open(t->pipe_odd);
	fd = file_open(t);
	if (dup2(fd, STDIN_FILENO) == -1)
		ft_putstr_fd("Error : [DUP2: due2 failed]\n", STDERR_FILENO);
	close(fd);
}

void	outfile_to_pipe(t_arg *t)
{
	int	fd;

	(void)t;
	(void)fd;
}

void	command_process(t_arg *t)
{
	int		pid;
	int		status;

	pid = fork();
	status = 0;
	if (pid == -1)
		ft_putstr_fd("Error : [fork: fork failed]\n", STDERR_FILENO);
	if (pid == 0)
	{
		if (t->curr_index == 1)
		{
			int i;
			char *tmp_path;

			i = 0;
			tmp_path = 0;
			while (t->path[i])
			{
				tmp_path = ft_strjoin(t->path[i], t->command[t->curr_index]);
				if (!access(tmp_path, X_OK))
					execve(tmp_path, &t->command[t->curr_index], t->envp);
				free(tmp_path);
				tmp_path = 0;
				i++;
			}
			// int i;

			// i = 0;
			// while (t->path[i])
			// {
				
			// 	// execv(t->path[i], &t->command[t->curr_index]);
				
			// 	printf("✅t->path[i]: %s &t->command[t->curr_index]: %s\n", t->path[i], t->command[t->curr_index]);
			// 	// printf("t->path[i]: %s\n , &t->command[t->curr_index]: %s\n", t->path[i], t->command[t->curr_index]);
			// 	// break ;
			// 	// i++;
			// 	i++;
			// }
		}
		else
		{
			
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		// if (WIFEXITED(status))
		// 	printf("Parent: Exited!\vExit Code is %d, Signal is %d\n", 
		// 		WEXITSTATUS(status), WTERMSIG(status));
		// else if (WIFSIGNALED(status))
		// 	printf("Parent: Signaled!\vExit Code is %d, Signal is %d\n", 
		// 		WEXITSTATUS(status), WTERMSIG(status));
		// else if (WIFSTOPPED(status))
		// 	printf("Parent: Stopped!\vExit Code is %d, Signal is %d\n", 
		// 		WSTOPSIG(status), WTERMSIG(status));
		// else if (WIFCONTINUED(status))
		// 	printf("Parent: Continued!\vExit Code is %d, Signal is %d\n", 
		// 		WSTOPSIG(status), WTERMSIG(status));
	}
	(void)t;
}

void	pipe_process(t_arg *t)
{
	infile_to_pipe(t);
	// while (t->curr_index <= t->max_index)
	// {
	command_process(t);
	// 	t->curr_index++;
	// }
	// outfile_to_pipe(t);
}
