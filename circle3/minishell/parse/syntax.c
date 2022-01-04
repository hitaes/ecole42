/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:35:10 by sgang             #+#    #+#             */
/*   Updated: 2022/01/04 13:35:12 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		set_redirect(t_dnode **token_list, t_ast **iter)
{
	t_token	*temp;

	temp = (*token_list)->data;
	(*iter)->type = temp->type;						// redirect 타입 저장
	(*token_list) = (*token_list)->next;
	temp = (*token_list)->data;
	(*iter)->data = temp->val;						// file path 저장
	temp->val = NULL;
	(*iter)->left = ft_calloc(1, sizeof(t_ast), 0);	// tree 확장
	(*iter) = (*iter)->left;
	return ;
}

// pipe일 경우 트리는 우측으로 확장한다.
static void		set_pipe(t_ast *parent, t_ast **it, t_cmd **cmd)
{
	t_ast	*new_node;

	if ((*cmd))
	{
		(*it)->type = DP_CMD;
		(*it)->data = *cmd;
		*cmd = NULL;
	}
	while (parent->right)
		parent = parent->right;
	new_node = ft_calloc(1, sizeof(t_ast), 0);
	parent->right = new_node;
	*it = parent->right;
}

// cmd는 가장 먼저 실행된다. 좌측 으로 확장된 가장 마지막 노드에 저장되어야 한다.
// 그러니 정보만 저장해준다.
static void		set_cmd(t_dnode **token_list, t_cmd **cmd)
{
	t_token	*token;

	token = (*token_list)->data;
	if (token->type == DP_CMD)
	{
		(*cmd) = ft_calloc(1, sizeof(t_cmd), 0);
		(*cmd)->args = slist_new_list();
		(*cmd)->cmd = token->val;
	}
	else if (token->type == DP_ARG)
		slist_ppback((*cmd)->args, token->val);
	token->val = NULL;
	return ;
}

static t_ast	*analyzer(t_dnode **token_list, t_slist *list, t_token *it_token)
{
	t_ast	*ret;
	t_ast	*it_ast;
	t_cmd	*cmd;

	ret = ft_calloc(1, sizeof(t_ast), 0);
	it_ast = ret;
	cmd = NULL;
	while ((*token_list)->data)
	{
		it_token = (t_token *)(*token_list)->data;
		if (it_token->type == DP_SEPARATE)
			break ;
		if (it_token->type == DP_CMD || it_token->type == DP_ARG)
			set_cmd(token_list, &cmd);
		else if (it_token->type >= DP_L_REDIRECT)
			set_redirect(token_list, &it_ast);
		else if (it_token->type == DP_PIPE)
			set_pipe(ret, &it_ast, &cmd);
		(*token_list) = (*token_list)->next;
	}
	if (cmd)
		it_ast->type = DP_CMD;
	it_ast->data = cmd;
	return (ret);
}

int	syntax(t_dlist *token_list, t_slist *list)
{
	t_dnode	*iter;

	iter = token_list->head->next;
	while (iter)
	{
		slist_ppback(list, analyzer(&iter, list, NULL));
		iter = iter->next;
	}
	return (0);
}