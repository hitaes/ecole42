/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:01:15 by pacman            #+#    #+#             */
/*   Updated: 2021/12/02 03:29:54 by pacman           ###   ########.fr       */
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
	if (p->state == _DIED)
		p->op->is_dead++;
	printf("%llu %d %s\n", ft_get_time() - p->op->st, p->id + 1, s);
	pthread_mutex_unlock(&p->op->print);
}
