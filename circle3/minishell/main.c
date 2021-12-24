/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:09:54 by sgang             #+#    #+#             */
/*   Updated: 2021/12/24 15:58:29 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>
#include <stdio.h>

void	ft_space_skip(char **str)
{
	while (**str && ft_isspace(**str))
		++(*str);
}

// custom ft_strchr
int	ft_strchr(char *charset, char ch)
{
	int	idx;

	idx = -1;
	while (*(charset + ++idx))
		if (*(charset + idx) == ch)
			return (idx);
	return (RET_ERROR);
}

int main(int ac, char **ag, char **envp)
{
	t_snode	*iter;
	char	str[100] = {0,};
	scanf("%[^\n]s", str);
	fflush(stdin);
	printf("%s\n", str);
	
	t_dlist *mylist;
	t_slist *ast;
	ast = slist_new_list();
	mylist = dlist_new_list();

	// while (1)
	// {
		int status = parser(mylist, ast, str);
		t_dnode *iiter = mylist->head->next;
		t_snode *list;
		list = iter;
		puts("=============lexical");
		while (status != RET_ERROR && iiter->data)
		{
			t_token *nnode = iiter->data;
			iiter = iiter->next;
			char *s = nnode->val;
			printf("type : %d] %s\n", nnode->type, s ? s : "");
		}
	// }
	return (0);
}
