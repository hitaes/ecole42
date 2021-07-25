/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:06:06 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/20 17:06:49 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buf;

	if (!(buf = malloc(size * count)))
		return (NULL);
	ft_memset(buf, 0, count * size);
	return (buf);
}
