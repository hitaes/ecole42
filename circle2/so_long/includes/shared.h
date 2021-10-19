/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:30:44 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/19 21:29:14 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include "env.h"
# include "../resources/minilibx_opengl_20191021/mlx.h"

// libft
int			ft_isdigit(char c);
long long	ft_atoi(const char *src);
int			ft_strlen(const char *s);
void		*ft_memset(void *b, int c, int len);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(char *s);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_get_next_line(int fd, char **line);
void		*replace(char **out, char *src);
char		*ft_itoa(int n);

// map
void		map_row_column(t_map *m);
void		map_frame_setter(t_map *m);
void		map_validator(t_map *m);
int			map_maker(t_game *g);
void		map_update(t_game *g, t_block *b);
void		map_finder(t_game *g, int argc, char **argv);
void		draw_mon(t_game *g, int state);
void		draw_coin(t_game *g, int state);
void		interval(t_game *g, time_t gap);
void		draw_sprite(t_game *g);

// game
void		game_init(t_game *g, t_map *m);
void		game_end(t_game *g);

// utils
void		ft_error_disposal(t_map *m, int message);
void		ft_free(void *ptr);
int			ft_keypress(int keycode, t_game *g);
void		ft_trace_setter(t_game *g);
void		ft_free_map(t_map *m);
int			ft_collision_check(t_game *g);

#endif
