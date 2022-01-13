/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:09:54 by sgang             #+#    #+#             */
/*   Updated: 2022/01/04 13:35:27 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>
#include <stdio.h>

void env_test(char **envp)
{
	char *str;
	t_dlist *env = env_init(envp);

	// env = env_init(envp);
	// env = dlist_new_list();
	// dlist_pback(env, env_set(0, "123=1"));
	// dlist_pback(env, env_set(0, "124=1"));
	// dlist_pback(env, env_set(0, "125=1"));
	// dlist_pback(env, env_set(0, "126=1"));
	// dlist_pback(env, env_set(0, "127=1"));

	int i = 0;
	t_dnode *iter = env->head->next;
	while (iter->next)
	{
		t_env *data = iter->data;
		printf("%d] %s=%s\n", i, (char*)data->key, (char*)data->val);
		printf("%d] %s\n", i, *(envp + i));
		++i;
		iter = iter->next;
	}
	// env_unset(env->head->next, "126");
	// env_unset(env->head->next, "123");
	// env_set(env_get(env->head, "124"), "124=2");

	puts("");
	iter = env->head->next;
	// while (iter->next)
	// {
	// 	t_env *data = iter->data;
	// 	printf("%d] %s=%s\n", i, (char*)data->key, (char*)data->val);
	// 	// printf("%d] %s\n", i, *(envp + i));
	// 	++i;
	// 	iter = iter->next;
	// }
	// while (1)
	// {
	// 	str = readline("bash : ");
	// 	add_history(str);
	// 	free(str);
	// 	str = NULL;
	// }

	puts("ENV END");
}

void	ft_space_skip(char **str)
{
	while (**str && ft_isspace(**str))
		++(*str);
}

int	ft_strchr(char *charset, char ch)
{
	int	idx;

	idx = -1;
	while (*(charset + ++idx))
		if (*(charset + idx) == ch)
			return (idx);
	return (RET_ERROR);
}

void test2(t_ast *ast, int depth)
{
	if (!ast || !ast->type)
		return ;
	if (ast->type >= DP_L_REDIRECT && ast->type <= DP_RR_REDIRECT)
	{
		printf("===REDIRECT=== %d]\n", depth);
		if (ast->type == DP_L_REDIRECT)
			puts("FD_IN");
		if (ast->type == DP_LL_REDIRECT)
			puts("FD_HEREDOC");
		if (ast->type == DP_R_REDIRECT)
			puts("FD_OUT");
		if (ast->type == DP_RR_REDIRECT)
			puts("FD_APPEND");
		puts((char *)ast->data);
	}
	else if (ast->type == DP_CMD)
	{
		t_cmd *cmd = ast->data;
		printf("===CMD=== %d]\n", depth);
		puts(cmd->cmd);
		t_snode *it = cmd->args->head->next;
		while (it)
		{
			printf("args: ");
			puts((char *)it->data);
			it = it->next;
		}
	}
	test2(ast->left, depth + 1);
	test2(ast->right, depth + 1);
}

int main(int ac, char **ag, char **envp)
{
	// env_test(envp);
	// while (1)
	// {
	// 	memset(str, 0, sizeof(str));
	// 	gets(str);
	// 	puts(str);
	// 	// str = readline("bash : ");
	// 	list = lexical_analyzer(str);
	// 	// add_history(str);
	// 	// free(str);
	// 	// str = NULL;
	// }
	// while (1)
	// {

	t_snode	*iter;
	char	str[100] = {0,};
	scanf("%[^\n]s", str);
	fflush(stdin);
	printf("%s\n", str);
	int status = 0;
	
	t_dlist *mylist;
	t_slist *ast;
	ast = slist_new_list();
	mylist = dlist_new_list();
	status = parser(mylist, ast, str);

	t_dnode *iiter = mylist->head->next;
	t_snode *list;
	list = iter;
	while (status != RET_ERROR && iiter->data)
	{
		t_token *nnode = iiter->data;
		iiter = iiter->next;
		char *s = nnode->val;
		printf("type : %d] %s\n", nnode->type, s ? s : "");
	}
	puts("==============lexical==============");
	int cnt = 0;
	t_snode *temp = ast->head->next;
	puts("=================MY SYNTEX=================");
	while (temp)
	{
		test2(temp->data, 0);
		temp = temp->next;
	}
	puts("==EXIT==");
	return (0);
}
