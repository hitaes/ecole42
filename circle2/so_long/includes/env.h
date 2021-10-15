/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:28:57 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/15 01:34:05 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# define FILE_PATH		"./resources/map/map.bar"
# define IMAGE_WALL 	"./resources/images/wall.xpm"
# define IMAGE_PLAYER 	"./resources/images/player.xpm"
# define IMAGE_EXIT 	"./resources/images/exit.xpm"
# define IMAGE_COIN 	"./resources/images/coin.xpm"
# define IMAGE_EMPTY 	"./resources/images/empty.xpm"
# define IMAGE_ENEMY 	"./resources/images/enemy.xpm"
# define PLAYER			80
# define EXIT			69
# define COIN			67
# define WALL			49
# define EMPTY			48
# define R				2
# define L				0
# define D				1
# define U				13
# define END			53
# define PIXEL_X		64
# define PIXEL_Y		64

/*
=======================================================

						Errors

=======================================================
*/
# define OTHER			101
# define NOWALL			102
# define PLAYERERROR	103
# define COINERROR		104
# define EXITERROR		105
# define RECERROR		106
# define NOTFOUNDERROR	107
# define MALERROR		108
# define GNLERROR		109
# define OPENERROR		110

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_coordinate {
	int			x;
	int			y;
}				t_coordinate;

typedef struct s_block {
	int				type;
	char			*path;
	t_coordinate	coord;
}					t_block;

typedef struct s_map {
	int				p;
	int				p_x;
	int				p_y;
	int				r_x;
	int				r_y;
	int				c;
	int				e;
	int				row;
	int				column;
	int				size_x;
	int				size_y;
	int				g_l;
	int				count;
	int				map_init;
	char			*map_path;
	char			*l;
	void			*mlx;
	void			*win;
	t_block			**f;
}					t_map;

typedef struct s_game {
	int				i;
	int				j;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*img;
	char			*addr;
	t_map			*m;
}					t_game;

#endif
