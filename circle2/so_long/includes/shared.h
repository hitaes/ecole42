/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:30:44 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/12 18:57:53 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include "env.h"
# include "../resources/minilibx_opengl_20191021/mlx.h"

// libft
int			ft_isdigit(char c);
long long	ft_atoi(const char *src);
int			ft_strlen(char *s);
void		*ft_memset(void *b, int c, int len);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(char *s);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_get_next_line(int fd, char **line);
void		*replace(char **out, char *src);

// map
void		map_validator(t_map *m);
void		map_init(t_map *m);

// utils
void		ft_error_disposal(void);
void		ft_free(void *ptr);

#endif
