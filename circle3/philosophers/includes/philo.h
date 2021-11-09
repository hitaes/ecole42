/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:14:11 by pac-man           #+#    #+#             */
/*   Updated: 2021/11/09 18:14:48 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// =============================================================================
// ERRORS
// =============================================================================
# define NB_PHILOS		0
# define TIME_DIE		1
# define TIME_EAT		2
# define TIME_NAP		3
# define NB_MEALS		4
# define WRONG_ARGS		100
# define INIT_FAILURE	99

typedef struct s_op
{
	int				d_settings[5];
}					t_op;

// =============================================================================
// LIBFT
// =============================================================================

void		*ft_memset(void *s, int c, size_t n);
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(char *s);
long long	ft_atoi(const char *src);

// =============================================================================
// UTILS
// =============================================================================

void		ft_error_disposal(int err_num);
int			ft_philo_init(t_op *op, int argc, char **argv);

#endif