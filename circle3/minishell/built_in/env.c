/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:37:33 by sgang             #+#    #+#             */
/*   Updated: 2021/12/18 20:17:27 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_unset(t_dnode *node, char *key)
{
	t_dnode	*iter;
	t_env	*temp;

	iter = env_get(node, key);
	if (iter)
	{
		temp = (t_env *)iter->data;
		free(temp->key);
		free(temp->val);
		free(temp->env);
		free(temp);
		dlist_delete_node(iter);
	}
	return ;
}

t_env	*env_set(t_env *node, char *env)
{
	const int	len = ft_strlen(env);
	char		*iter;
	t_env		*ret;

	iter = env;
	while (*iter && *iter != '=')
		++iter;
	if (*iter == '\0')
		return (0);
	ret = node;
	if (ret == NULL)
		ret = ft_calloc(1, sizeof(t_env), 0);
	free(ret->val);
	free(ret->key);
	free(ret->env);
	ret->env = ft_calloc(1, len, 0);
	ft_memcpy(ret->env, env, len);
	ret->key = ft_calloc(1, iter - env + 1, 0);
	ft_memcpy(ret->key, env, iter - env);
	++iter;
	ret->val = ft_calloc(1, len - (iter - env) + 1, 0);
	ft_memcpy(ret->val, iter, len - (iter - env));
	return (ret);
}

t_dnode	*env_get(t_dnode *iter, char *key)
{
	t_env	*node;

	while (iter->next)
	{
		node = (t_env *)iter->data;
		if (!ft_strcmp(key, node->key))
			return (iter);
		iter = iter->next;
	}
	return (0);
}

t_dlist	*env_init(char **envp)
{
	t_dlist	*env;
	char	*iter;
	int	idx;

	idx = -1;
	env = dlist_new_list();
	while (*(envp + ++idx))
		dlist_pback(env, env_set(NULL, *(envp + ++idx)));
	return (env);
}