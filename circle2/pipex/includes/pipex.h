/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:57:56 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/23 17:45:25 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>

// =============================================================================
// STRUCT
// =============================================================================

typedef struct s_arg
{
	int		pipe_count;
	int		count;
	char	**path;
	char	**command;
	char	**cmd[3];
	char	**envp;
	int		p1[2];
	int		p2[2];
}			t_arg;

// =============================================================================
// LIBFT
// =============================================================================

size_t	ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);
bool	ft_calloc(void **ptr, size_t cnt, size_t n);
char	*ft_strdup(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
bool	ft_isspace(int c);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strndup(const char *src, size_t size);

// =============================================================================
// UTILS
// =============================================================================

size_t	char_frequency(char *s, char c);
void	arg_init(t_arg *t, char **envp, char **argv, int argc);
char	*substr(char *s, int from, int to);
void	t_arg_init(t_arg *t);
void	pipe_process(t_arg *t);
void	child_proc(t_arg *t, int i);
void	parent_prc(t_arg *t, int i, int pid);
void	pipe_process(t_arg *t);
int		file_open(char *file, int mode);
void	exec_cmd(t_arg *t, int i);
void	set_pipe_for_infile(t_arg *t);
void	infile_to_pipe(t_arg *t, int i);
void	set_pipe_for_outfile(t_arg *t, int i);
void	set_pipe_for_middle(t_arg *t, int i);
void	outfile_from_pipe(t_arg *t, int i);
void	free_p(void *s);

#endif