/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:28:57 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/12 19:33:52 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# define FILE_MAP	 	"./resources/map/map.bar"
# define IMAGE_WALL 	"./resources/images/wall.xpm"
# define IMAGE_PLAYER 	"./resources/images/player.xpm"
# define IMAGE_EXIT 	"./resources/images/exit.xpm"
# define IMAGE_COIN 	"./resources/images/coin.xpm"
# define IMAGE_EMPTY 	"./resources/images/empty.xpm"
# define IMAGE_ENEMY 	"./resources/images/enemy.xpm"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_coordinate {
	int x;
	int y;
}			t_coordinate;

typedef struct s_block {
	int				index;
	int				type;
	t_coordinate	coord;
}			t_block;

typedef struct s_map {
	int		p;
	int		c;
	int		e;
	int		size_x;
	int		size_y;
	int		g_l;
	int		count;
	char	*l;
	t_block	*b_l;
} 			t_map;

typedef struct s_game {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_game;

#endif
