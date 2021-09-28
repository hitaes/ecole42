/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:00:08 by pac-man           #+#    #+#             */
/*   Updated: 2021/09/28 16:20:51 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_X
# define PIPE_X

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

typedef struct t_cmds{
	char *i;
	char *o;
	int cc;
	int pi;
} cmds;

void	cmds_init(cmds *tmp_cmds, int argc, char **argv);
void	cmds_check_and_set(cmds *tc, char **argv, char **envp);

#endif