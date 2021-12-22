/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:01:13 by pacman            #+#    #+#             */
/*   Updated: 2021/12/23 00:13:21 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

char	*command_checker(t_arg *t, int i)
{
	int		j;
	char	*tmp_path;

	j = 0;
	tmp_path = 0;
	while (t->path[j])
	{
		tmp_path = ft_strjoin(t->path[j], t->command[i]);
		if (!access(tmp_path, X_OK))
			return (tmp_path);
		free(tmp_path);
		tmp_path = 0;
		j++;
	}
	return (NULL);
}
