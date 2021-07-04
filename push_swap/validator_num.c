/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeskim <taeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:29 by taeskim           #+#    #+#             */
/*   Updated: 2021/06/15 13:46:39 by taeskim          ###   ########.fr       */
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

void			validator_int(char *s)
{
	long long	num;
	int s_len;
	
	num = 0;
	s_len = ft_strlen(s);
	if (s_len > 12)
		exit(1);
	else
	{
		num = atoi(s);
		if (num <= INT_MAX && num >= INT_MIN)
			printf("|💚%d|", (int)num);
		else
			exit(1);
	}
}

// 1.2 입력값 중에 문자가 있으면 0을 반환하면서 종료, 
// 앞자리가 0이라면 0 제거(atoi에서 10을 곱하는 과정에서 자연스럽게 처리됨.)

void		validator_num(char *s)
{
	int		i;

	i = 0;
	if (!(s[i]))
	// ❓ 아무것도 없을 때 어떻게 처리 해야 할까?
	// ❓ exit로 나가면서 Error를 어떻게 찍을까?
		exit(1);
	while (s[i])
	{
		if (!(ft_isdigit(s[i])))
			exit(1);
		i++;
	}
	validator_int(s);
}
