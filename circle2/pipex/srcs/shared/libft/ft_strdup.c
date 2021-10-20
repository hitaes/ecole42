/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:59:53 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/20 17:06:52 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*buff;

	len = ft_strlen(s);
	if (!ft_calloc((void **)(&buff), len + 1, sizeof(char)))
		return (NULL);
	ft_strlcpy(buff, s, len + 1);
	return (buff);
}
