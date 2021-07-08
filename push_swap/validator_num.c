/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:29 by taeskim           #+#    #+#             */
/*   Updated: 2021/07/08 19:32:39 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1.5 동일한 입력값이 존재하는지 확인하기

/* 1.4
	검증된 값들을 어디다 어떻게 저장할 것인가?
*/

/* 1.3 입력값이 int 타입인지 확인함.
 어떤 속성을 가지고 있을까?
 부호를 제외한 길이가 10이상이라면 exit(1)
 미만이라면 long long으로 받아서 int min || int max인지 구분하기

 */

int				validator_int(char *s)
{
	long long	num;
	int			s_len;

	num = 0;
	s_len = ft_strlen(s);
	if (s_len > 12)
		return (0);
	else if (s_len >= 11 && s[0] != '-')
		return (0);
	else
	{
		num = ft_atoi(s);
		if (num <= INT_MAX && num >= INT_MIN)
			return ((int)num);
		else
			return (0);
	}
}

// 1.2 입력값 중에 문자가 있으면 0을 반환하면서 종료,
// 앞자리가 0이라면 0 제거(atoi에서 10을 곱하는 과정에서 자연스럽게 처리됨.)

int		validator_num(char *s)
{
	int		i;

	i = 0;
	if (!(s[i]))
		return (0);
	while (s[i])
	{
		if (!(ft_isdigit(s[i])) && s[0] != '-')
			return (0);
		i++;
	}
	return (validator_int(s));
}
