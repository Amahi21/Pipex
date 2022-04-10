#include "pipex.h"

void	first_child(t_info *p)
{
	dup2(p->outfile, 1);
	dup2(p->pipe[0], 0);
	close(p->pipe[0]);
	close(p->pipe[1]);
	execve(p->cmd1, p->cmd1_av, p->env);
}

void	second_child(t_info *p)
{
	dup2(p->fd2, 1);
	dup2(p->pipe[0], 0);
	close(p->pipe[0]);
	execve(p->cmd2, p->cmd2_av, p->env);
}