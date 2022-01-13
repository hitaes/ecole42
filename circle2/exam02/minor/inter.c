/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.
The display will be followed by a \n.
If the number of arguments is not 2, the program displays \n.
Examples:
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$
*/
#include <unistd.h>

// int main(int argc, char *argv[])
// {
// 	int i;
// 	int j;
// 	int temp;

// 	if (argc != 3)
// 		return (0);
// 	i = 0;
// 	while (argv[1][i])
// 	{
// 		j = 0;
// 		while (argv[2][j])
// 		{
// 			if (argv[1][i] == argv[2][j])
// 			{	
// 				temp = i;
// 				while (argv[1][--temp] && temp >= 0)
// 				{	
// 					if (argv[1][temp] == argv[1][i])
// 						break;
// 				}
// 				if (temp < 0)
// 					write(1, &argv[1][i], 1);
// 				break;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
int ft_appear(char *s, char c, int i)
{
	int j;

	j = -1;
	while (++j < i)
		if (s[j] == c)
			return (0);
	return (1);
}

int main(int argc, char **argv)
{
	int i;
	int j;
	int tmp;

	if (argc != 3)
		return (0);
	i = -1;
	j = -1;
	tmp = 0;
	while (argv[1][++i])
	{
		while (argv[2][++j])
		{
			if (argv[1][i] == argv[2][j])
			{
				tmp = i;
				while (argv[1][--tmp] && tmp >= 0)
				{
					if (argv[1][tmp] == argv[1][i])
						break ;
				}
				if (tmp < 0)
					write(1, &argv[1][i], 1);
				break ;
			}
		}
	}
	return (0);
}