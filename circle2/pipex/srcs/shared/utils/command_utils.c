/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:01:13 by pacman            #+#    #+#             */
/*   Updated: 2021/12/23 04:15:40 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

int	is_space(char *s)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			ret = 1;
		i++;
	}
	return (ret);
}

char	*command_checker(t_arg *t, int i)
{
	int		j;
	char	*tmp_path;
	char	*tmp;
	char	*tmp_cmd;

	j = 0;
	tmp_path = 0;
	while (t->path[j])
	{
		tmp_cmd = ft_strdup(t->command[i]);
		if (is_space(t->command[i]))
		{
			tmp = ft_strchr(t->command[i], ' ');
			tmp_cmd[ft_strlen(t->command[i]) - ft_strlen(tmp)] = 0;
		}
		tmp_path = ft_strjoin(t->path[j], tmp_cmd);
		if (!access(tmp_path, X_OK))
			return (tmp_path);
		free(tmp_path);
		tmp_path = 0;
		j++;
	}
	return (NULL);
}
