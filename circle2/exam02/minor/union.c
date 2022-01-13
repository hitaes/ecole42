/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.
The display will be in the order characters appear in the command line, and
will be followed by a \n.
If the number of arguments is not 2, the program displays \n.
Example:
$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/
#include	<unistd.h>

int ft_appear(char *s, char c, int i)
{
	int j;

	j = -1;
	while (++j < i)
		if (s[j] == c)
			return (0);
	return (1);
}

void ft_union(char *s1, char *s2)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (s1[++i])
		if (ft_appear(s1, s1[i], i))
			write(1, &(s1[i]), 1);
	while (s2[++j])
		if (ft_appear(s2, s2[j], j) && ft_appear(s1, s2[j], i))
			write(1, &(s2[j]), 1);
}

int main(int argc, char **argv)
{
	char c;

	c = '\n';
	if (argc != 3)
	{
		write(1, &c, 1);
		return (0);
	}
	ft_union(argv[1], argv[2]);
	write(1, &c, 1);
	return (0);
}
