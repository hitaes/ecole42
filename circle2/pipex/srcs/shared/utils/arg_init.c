/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:27:43 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/20 18:07:05 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	arg_init(t_arg *t, char **envp)
{
	while (*envp && ft_strncmp(*envp, "PATH", 4))
		++envp;
	if (!(*envp))
		error_disposal(t, ENVPATHERROR);
	t->count = char_frequency(*envp, ':');
	t->path = (char **)malloc(sizeof(char *) * t->count);
	if (t->path == NULL)
		error_disposal(t, MALERROR);
	str_slicer(t, *envp);
}
