#include "pipex.h"

void	all_free(t_info *p)
{
	close(p->infile);
	close(p->outfile);
	free(p);
}