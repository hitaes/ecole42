/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:55:19 by pac-man           #+#    #+#             */
/*   Updated: 2021/09/28 16:22:24 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(int argc, char **argv, char **envp)
// {
// 	cmds	cmds;
// 	// pid_t	pid;

// 	if (argc >= 5)
// 	{
// 		cmds_init(&cmds, argc, argv);
// 		cmds_check_and_set(&cmds, argv, envp);
// 		// if (pid)
// 		// {
// 		// 	pid = fork();
// 		// 	printf("child - cmds.i : %s\n", cmds.i);
// 		// 	printf("child - cmds.o : %s\n", cmds.o);
// 		// }
// 		// else
// 		// {
// 		// 	printf("parent - cmds.i : %s\n", cmds.i);
// 		// 	printf("parent - cmds.o : %s\n", cmds.o);
// 		// }
// 	}
// 	else
// 		exit(1);
// 	return (0);
// }

int	main(void)
{
	int	mode;

	mode = 0;
	mode |= F_OK;
	if (!access("test.txt", mode))
		printf("✅File is existing\n");
	else
		printf("✅File is not here\n");
	return (0);
}
