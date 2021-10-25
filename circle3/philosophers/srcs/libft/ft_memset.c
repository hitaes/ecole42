/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:15:51 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/21 16:56:00 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
	{
		printf("✅%s, %d\n", ((unsigned char *)s), (unsigned char)c);
		((unsigned char *)s)[i] = (unsigned char)c;
	}
	return (s);
}
