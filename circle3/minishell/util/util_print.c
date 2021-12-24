/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:30:51 by sgang             #+#    #+#             */
/*   Updated: 2021/12/12 17:49:09 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_putnum(int num)
{
	if (num > 9)
		ft_putnum(num / 10);
	ft_putchar(num % 10 + '0');
}

void	ft_putchar(char ch)
{
	const unsigned char	c = ch;

	write(1, &c, 1);
}

void	ft_puts(char *msg)
{
	const unsigned char	*m = (unsigned char *)msg;

	write(1, m, ft_strlen(msg));
}

void	ft_puts_fd(char *msg, int fd)
{
	const unsigned char	*m = (unsigned char *)msg;

	write(fd, m, ft_strlen(msg));
}
