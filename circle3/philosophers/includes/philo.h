/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:14:11 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/22 14:02:24 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_op
{
	int				total;
	int				time_die;
	int				time_eat;
	int				time_nap;
	int				limit;
	int				meet;
	long long		begin;
}					t_op;


// =============================================================================
// LIBFT
// =============================================================================

void	*ft_memset(void *s, int c, size_t n);


#endif