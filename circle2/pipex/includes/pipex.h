/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:57:56 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/20 18:06:36 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>

// =============================================================================
// STRUCT
// =============================================================================

typedef struct s_arg
{
	int		count;
	char	**path;
}			t_arg;

// =============================================================================
// ERRORS
// =============================================================================
# define MALERROR 0
# define ENVPATHERROR 1

// =============================================================================
// LIBFT
// =============================================================================

size_t	ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);
bool	ft_calloc(void **ptr, size_t cnt, size_t n);
char	*ft_strdup(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// =============================================================================
// UTILS
// =============================================================================

size_t	char_frequency(char *s, char c);
void	error_disposal(t_arg *t, int message);
void	arg_init(t_arg *t, char **envp);
char	*substr(t_arg *t, char *s, int from, int to);
void	str_slicer(t_arg *t, char *s);

#endif