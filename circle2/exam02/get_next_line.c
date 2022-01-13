/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:25:09 by pacman            #+#    #+#             */
/*   Updated: 2021/12/14 17:32:28 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int ft_strlen(char *s)
{
    int len = 0;
    while (*s++)
        len++;
    return len;


    while (*s++ && ++len)
        // len++;



    int len;

    len = -1;
    while (s[++len])
        ;
    return (len);
}

char *ft_strjoin(char *s1, char *s2)
{
    // int i;
    // int j;
    int sl1;
    int sl2;
    char *tmp;
    char *bck;

    // i = -1;
    // j = -1;
    sl1 = ft_strlen(s1);
    sl2 = ft_strlen(s2);
    tmp = (char *)malloc(sl1 + sl2 + 1);
    bck = tmp;
    if (!tmp)
        return (NULL);
    while (*tmp++ = *s1++)
        ;
    while (*tmp++ = *s2++)
        ;
    tmp[sl1 + sl2] = 0;

    // while (s1[++i])
    //     tmp[i] = s1[i];
    // while (s2[++j])
    // {
    //     tmp[i] = s2[j];
    //     i++;
    // }

    // tmp[i] = 0;
    // return (tmp);
    return (bck);
}

int ft_strchar(char *s, char c)
{
    int i;

    i = -1;
    while (s[++i])
        if (s[i] == c)
            return (i);
    return (-1);
}

char *ft_strdup(char *s)
{
    int i;
    char *tmp;

    i = -1;
    tmp = 0;
    while (s[++i])
    {
        tmp = (char *)malloc(ft_strlen(s));
        if (!tmp)
            return (NULL);
        tmp[i] = s[i];
    }
    tmp[i] = 0;
    return (tmp);    
}

char	*get_next_line(int fd)
{
    char     buff[1000000];
    static 
    char*    data;
    int      ret;
    char*    tmp;

    tmp = 0;
    if ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        ret = ft_strchar(buff, '\n');
        while (ret != -1)
        {
            tmp = buff;
            tmp[ret] = 0;
            data = ft_strjoin(data, tmp);
            tmp = buff + ret + 1;
            ret = ft_strchar(tmp, '\n');
        }
        data = ft_strjoin(data, tmp);
    }
    return (data);
}