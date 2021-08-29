/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:06:06 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/29 22:18:50 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buf;

	buf = (char *)malloc(count * size);
	if (!(buf))
	{
		free(buf);
		buf = 0;
		exit(1);
	}
	ft_memset(buf, 0, count * size);
	return (buf);
}
