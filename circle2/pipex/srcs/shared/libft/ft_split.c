/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:58:32 by pacman            #+#    #+#             */
/*   Updated: 2021/12/23 14:17:37 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

static size_t	strlen_ch(const char *str, char ch)
{
	size_t	i;

	i = 0;
	while (*str != ch && *str)
	{
		str++;
		i++;
	}
	return (i);
}

static size_t	split_next_idx(const char *str, char ch)
{
	size_t	i;

	i = 0;
	while (*str != ch && *str)
	{
		i++;
		str++;
	}
	while (*str == ch && *str)
	{
		i++;
		str++;
	}
	return (i);
}

static void	delimiter_count(size_t *delimited, const char *s, char c)
{
	size_t	i;

	*delimited = 0;
	i = 0;
	while (s[i])
	{
		(*delimited)++;
		i += split_next_idx(&s[i], c);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	delimited;
	size_t	i;

	if (!s)
		return (NULL);
	while (*s == c && c != '\0')
		s++;
	delimiter_count(&delimited, s, c);
	strs = malloc(sizeof(char *) * (delimited + 1));
	if (!strs)
		return (0);
	i = 0;
	while (i < delimited)
	{
		strs[i++] = ft_strndup(s, strlen_ch(s, c));
		s += split_next_idx(s, c);
	}
	strs[i] = NULL;
	return (strs);
}
