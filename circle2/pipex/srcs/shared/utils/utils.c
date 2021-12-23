/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:20:07 by pacman            #+#    #+#             */
/*   Updated: 2021/12/23 14:11:07 by pacman           ###   ########.fr       */
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
	char	**cmd;
	char	*path;
	int		j;

	j = 0;
	cmd = ft_split(t->command[i + 1], ' ');
	while (t->path[j])
	{
		path = ft_strjoin(t->path[j], *cmd);
		if (!access(path, X_OK))
			break ;
		free_p(path);
		j++;
	}
	if (!path)
		printf("cmd is null");
	execve(path, cmd, t->envp);
}
