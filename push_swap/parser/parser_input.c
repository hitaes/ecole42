/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 01:22:24 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/25 20:54:38 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char *append_char(char *str, char c)
{
	int l;

	l = ft_strlen(str);
	if (str)
		ft_clean(str);
	str = (char *)malloc(l + 2);
	if (!(str))
		return (0);
	str[l] = c;
	str[l + 1] = 0;
	return (str);
}

// char **parser_input(int argc, int count, char **argv)
// {
// 	int i;
// 	int j;
// 	int k;
// 	char *tmp;
// 	char **v_str;

// 	/*✅ 1.1 빈칸이 나오면 문자가 나올때까지 index를 높이고
// 		 1.2 문자가 나오면 해당 포인터를 tmp에 */
// 	i = 0;
// 	j = -1;
// 	k = 0;
// 	v_str = (char **)malloc(sizeof(char **) * count);
// 	if (!(v_str))
// 		return (NULL);
// 	while (++i < argc)
// 	{
// 		while (argv[i][++j])
// 		{
// 			if (!(argv[i][j] == ' '))
// 			{
// 				v_str[k] = append_char(v_str[k], argv[i][j]);
// 			}
// 			else
// 				k++;
// 		}
// 		k++;
// 		j = -1;
// 	}
// 	return (v_str);
// }

char **parser_input(int argc, char **argv)
{
	char *tmp;
	char **v_str;
	int i;
	int j;
	int count;
	int digit_appear;

	i = 0;
	j = -1;
	count = 0;
	digit_appear = 0;
	v_str = (char **)malloc(sizeof(char **) * 4);
	if (!(v_str))
		return (NULL);
	while (++i < argc)
	{
		while (argv[i][++j])
		{
			if (!digit_appear && ft_isdigit(argv[i][j]))
				digit_appear = 1;
			if (digit_appear && argv[i][j] == ' ')
			{
				digit_appear = 0;
				tmp = 0;
				count++;
			}
			else
				tmp = append_char(tmp, argv[i][j]);
		}
		if (digit_appear)
		{
			digit_appear = 0;
			tmp = 0;
			count++;
		}
		j = -1;
	}

	return (v_str);
}
