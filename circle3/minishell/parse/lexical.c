/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:10:57 by sgang             #+#    #+#             */
/*   Updated: 2022/01/04 13:35:14 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	token_get_type(t_token *prev, t_token *cur, int *type)
{
	if (prev && prev->type > DP_PIPE)						// 리다리엑트 후에는 무조건 경로이다.
		cur->type = DP_FILE;
	else if (!prev || ((*type & DP_CMD) != DP_CMD))			// < a echo echo1 echo2 echo3 < a echo4 echo5
	{														// 위 명령어에서 CMD는 echo 하나이다.
		*type = DP_CMD;										// echo1~5까지는 echo의 ARG로 취급된다.
		cur->type = DP_CMD;
	}
	else
		cur->type = DP_ARG;									// 그러니 FILE_PATH와 CMD를 제외하곤 전부다 ARG로 취급
}															// echo < fail | echo a CMD가 2개 리다이렉션이 실패해도 후자는 실행된다.
															// echo < fail ; echo suc CMD가 2개 이것도한 실패해도 후자가 실행된다. 두개의 차이가 애매모호
static int	token_other(t_dnode *list, char **str, int *type)
{
	const char		*iter = *str;
	const t_token	*prev = (t_token *)list->prev->data;
	t_token			*cur;
	int				ret;
	int				flag;

	ret = 0;
	cur = (t_token *)list->data;
	while (**str)
	{
		if (!ret && (ft_strchr(TOKEN, **str) != RET_ERROR || ft_isspace(**str)))
			break ;
		flag = ft_strchr(QUTOES, **str);
		if (flag != RET_ERROR && (!ret || ret == flag + 1))
			ret ^= (flag + 1);
		++(*str);
	}
	cur->val = ft_calloc(1, *str - iter + 1, 0);
	ft_memcpy(cur->val, (char *)iter, *str - iter);
	token_get_type((t_token *)prev, cur, type);
	return (ret);
}

static int	token_operator(t_dnode *iter, char **str, int *type)
{
	const int		idx =  ft_strchr(TOKEN, **str);
	const t_token	*prev = (t_token *)(iter->prev)->data;
	t_token			*cur;
	int				temp;

	if (idx == RET_ERROR)
		return (token_other(iter, str, type));
	++(*str);
	cur = (t_token *)(iter)->data;
	temp = ft_strchr(TOKEN, **str);							// 예외 3개
	if (temp != RET_ERROR && (idx < 2 || idx != temp))		// 리다이렉트 인데 페어가 맞지 않다면 에러
		return (RET_ERROR);									// ex) <> ><
	if (idx < 2 && (!prev || !(prev->type & 1)))			// 유효하지 않은 명령어인데 세퍼레이트와 파이프가 나오는 경우
		return (RET_ERROR);									// ex) < | echo a, a < ; echo a
	if (idx > 1 && prev && prev->type > DP_PIPE)			// 리다이렉트 후에 리다이렉트가 나오면 에러
		return (RET_ERROR);									// ex) < < echo a
	cur->type = (1 << (idx + 3));
	if (temp == idx)
	{
		++(*str);
		cur->type = (1 << (idx + 3)) + 2;
	}
	if (cur->type == DP_SEPARATE || cur->type == DP_PIPE)	// token_get_type함수 에서 사용(15 번째줄 참조)
		*type = 0;
	return (0);
}

static int	lexical(t_dlist *list, char *str)
{
	t_token	*temp;
	int		type;

	type = 0;
	while (*str)
	{
		dlist_pback(list, NULL);
		list->tail->prev->data = ft_calloc(1, sizeof(t_token), 0);
		if (token_operator(list->tail->prev, &str, &type))
			return (RET_ERROR);
		ft_space_skip(&str);
	}
	temp = list->tail->prev->data;
	if (temp->type > DP_SEPARATE)
		return (RET_ERROR);
	return (0);
}

int	parser(t_dlist *list, t_slist *ast, char *str)
{
	int	status;

	status = lexical(list, str);
	if (status)
		return (status);
	status = syntax(list, ast);
	return (status);
}
