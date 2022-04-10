#include "pipex.h"

void	out_2p(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			write(1, &str[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}
void	out_1p(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}