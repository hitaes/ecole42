/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:17:14 by pacman            #+#    #+#             */
/*   Updated: 2021/11/27 21:47:21 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_state(t_philo *p, char *s)
{
	pthread_mutex_lock(&p->op->print);
	if (p->op->f_philo == p->op->d_settings[NB_PHILOS] || p->op->is_dead)
	{
		pthread_mutex_unlock(&(p->op->death_checker));
		return ;
	}
	printf("%llu %d %s\n", ft_get_time() - p->op->st, p->id + 1, s);
	if (p->state == _DIED)
		p->op->is_dead++;
	pthread_mutex_unlock(&p->op->print);
}

void	pick_up(t_philo *p)
{
	pthread_mutex_lock(&(p->op->forks[p->left_fork_id]));
	print_state(p, "has taken a fork");
	pthread_mutex_lock(&(p->op->forks[p->right_fork_id]));
	print_state(p, "has taken a fork");
}

void	put_down(t_philo *p)
{
	while (ft_get_time() - p->last_meal < p->op->d_settings[TIME_EAT])
		usleep(10);
	pthread_mutex_unlock(&(p->op->forks[p->left_fork_id]));
	pthread_mutex_unlock(&(p->op->forks[p->right_fork_id]));
}

void	eating(t_philo *p)
{
	p->state = _EATING;
	p->eat_count++;
	print_state(p, "is eating");
	p->last_meal = ft_get_time();
	if (p->eat_count == p->op->d_settings[NB_SERVINGS])
	{
		pthread_mutex_lock(&(p->op->nb_aia));
		p->state = _DONE;
		p->op->f_philo++;
		pthread_mutex_unlock(&(p->op->nb_aia));
	}
	if (p->op->f_philo == p->op->d_settings[NB_PHILOS])
		pthread_mutex_unlock(&(p->op->death_checker));
}

void	sleeping_then_thinking(t_philo *p)
{
	p->state = _SLEEPING;
	print_state(p, "is sleeping");
	while (ft_get_time() - p->last_meal
		< p->op->d_settings[TIME_NAP] + p->op->d_settings[TIME_EAT])
		usleep(10);
	p->state = _THINKING;
	print_state(p, "is thinking");
}
