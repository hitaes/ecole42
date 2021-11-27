/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:39:22 by pacman            #+#    #+#             */
/*   Updated: 2021/11/27 22:00:28 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clear_op(t_op *op, int con)
{
	int	i;

	i = -1;
	if (con == 2)
	{
		while (++i < op->d_settings[NB_PHILOS])
		{
			pthread_mutex_destroy(op->philos[i]);
			pthread_mutex_destroy(&(op->forks[i]));
		}
	}
	if (op->philos)
	{
		free(op->philos);
		op->philos = 0;
	}
	if (op->forks)
	{
		free(op->forks);
		op->forks = 0;
	}
}

void	*philosopher(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (!(p->id % 2))
		usleep(1000);
	while (p->state <= _SLEEPING)
	{
		pick_up(p);
		eating(p);
		put_down(p);
		sleeping_then_thinking(p);
	}
	return (NULL);
}

	// ✅출력을 뮤텍스로 묶기
	// ✅detach
	// ✅교착상태 해결 하는 부분이 필요하다.
	// ✅ timestamp는 시간 마다 찍는거
	// 끝나는 케이스 eat count 챙기기
	// 끝나는 케이스 죽는 케이스 트레킹하기
	// 종료시 free해주기
	// 0으로 입력되는 이가 무엇
void	*monitor(void *philo)
{
	t_philo		*p;
	long long	ct;

	p = (t_philo *)philo;
	while (p->state <= _SLEEPING && !p->op->is_dead)
	{
		ct = ft_get_time() - p->last_meal;
		if (ct > p->op->d_settings[TIME_DIE])
		{
			p->state = _DIED;
			print_state(p, "died");
			pthread_mutex_unlock(&p->op->death_checker);
			break ;
		}
	}
	return (NULL);
}

int	thread_start(t_op *op)
{
	int			i;
	pthread_t	tid;

	i = -1;
	while (++i < op->d_settings[NB_PHILOS])
	{
		if (pthread_create(&(tid), NULL, philosopher, &(op->philos[i]))
			|| pthread_detach(tid))
			return (1);
		if (pthread_create(&(tid), NULL, monitor, &(op->philos[i]))
			|| pthread_detach(tid))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_op		op;
	int			i;

	i = -1;
	ft_memset(&op, 0, sizeof(t_op));
	if (ft_parser(&op, argc, argv))
		ft_error_disposal("ERROR_PARSING");
	else if (ft_init(&op))
		ft_error_disposal("ERROR_INIT_FAILURE");
	else if (thread_start(&op))
		ft_error_disposal("ERROR_THREAD");
	pthread_mutex_lock(&(op.death_checker));
	pthread_mutex_unlock(&(op.death_checker));
	clear_op(&op, 2);
	return (0);
}
