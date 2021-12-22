/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:20:07 by pacman            #+#    #+#             */
/*   Updated: 2021/12/23 02:19:20 by pacman           ###   ########.fr       */
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

void	exec_cmd(t_arg *t, int i)
{
	char	*cmd;
	char	*arg[2];

	cmd = command_checker(t, i + 1);
	if (!cmd)
		printf("cmd is null");
	arg[0] = t->command[i + 1];
	arg[1] = 0;
	execve(cmd, arg, t->envp);
}
