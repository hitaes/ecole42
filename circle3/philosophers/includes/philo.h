/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:14:11 by pac-man           #+#    #+#             */
/*   Updated: 2021/11/11 00:51:28 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

// =============================================================================
// INDEX
// =============================================================================

# define NB_PHILOS				0
# define TIME_DIE				1
# define TIME_EAT				2
# define TIME_NAP				3
# define NB_SERVINGS			4

// =============================================================================
// ERRORS
// =============================================================================

# define ERROR_PARSING			100
# define ERROR_WRONG_ARGS		99
# define ERROR_INIT_FAILURE		98

typedef enum e_state
{
	_THINKING,
	_EATING,
	_SLEEPING
}			t_state;

typedef struct s_op
{
	int				d_settings[5];
	t_state			*states;
	pthread_mutex_t	mutex_lock;
	pthread_cond_t	*cond_vars;
}					t_op;

// =============================================================================
// LIBFT
// =============================================================================

void		*ft_memset(void *s, int c, size_t n);
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(char *s);
long long	ft_atoi(const char *src);
int			ft_isdigit(char c);

// =============================================================================
// UTILS
// =============================================================================

void		ft_error_disposal(int err_num);
int			ft_init(t_op *op, int argc, char **argv);
int			ft_parser(int argc, char **argv);

#endif