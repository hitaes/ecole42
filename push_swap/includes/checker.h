/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 14:21:28 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/30 01:18:21 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "shared.h"

//	checker
int		ft_do_checker(t_stack *s_a, t_stack *s_b, char *line);
void	ft_gnl_check(t_stack *s_a, t_stack *s_b);

#endif
