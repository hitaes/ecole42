/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:14:11 by pac-man           #+#    #+#             */
/*   Updated: 2021/11/29 23:38:36 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

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
# define ERROR_THREAD			99
# define ERROR_INIT_FAILURE		98

struct	s_op;

typedef enum e_state
{
	_THINKING,
	_EATING,
	_SLEEPING,
	_DIED,
	_DONE,
}			t_state;

typedef struct s_op
{
	int				d_settings[5];
	int				f_philo;
	int				is_dead;
	long long		st;
	pthread_mutex_t	nb_aia;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_checker;
	pthread_mutex_t	print;
}					t_op;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				left_fork_id;
	int				right_fork_id;
	long long		last_meal;
	t_state			state;
	t_op			*op;
}			t_philo;

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

void		ft_error_disposal(char *s);
int			ft_parser(t_op *op, int argc, char **argv);
int			ft_init(t_op *op, t_philo **philos);
long long	ft_get_time(void);
void		pick_up(t_philo *p);
void		put_down(t_philo *p);
void		eating(t_philo *p);
void		sleeping_then_thinking(t_philo *p);
void		print_state(t_philo *p, char *s);
void		take_your_time(t_philo *p, int opt);

#endif