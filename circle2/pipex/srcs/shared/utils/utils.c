/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:20:07 by pacman            #+#    #+#             */
/*   Updated: 2021/12/23 22:48:26 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

int	file_open(t_arg *t, char *file, int mode)
{
	int	fd;

	fd = open(file, mode);
	if (fd < 0)
		error_disposal(t, "Error: open\n", STDIN_FILENO);
	return (fd);
}

void	exec_cmd(t_arg *t, int i)
{
	char	**cmd;
	char	*path;
	int		j;

	j = 0;
	cmd = ft_split(t->command[i + 1], ' ');
	while (t->path[j])
	{
		t->path[j] = ft_strjoin(t->path[j], "/");
		path = ft_strjoin(t->path[j], *cmd);
		if (!access(path, X_OK))
			break ;
		j++;
	}
	if (!path)
		error_disposal(t, "Error: cmd\n", STDIN_FILENO);
	execve(path, cmd, t->envp);
}
