#include "pipex.h"

void	error(char *error)
{
	int	i;

	i = 0;
	while (error[i])
		write(1, &error[i++], 1);
	exit(0);
}