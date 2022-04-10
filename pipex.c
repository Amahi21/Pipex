#include "pipex.h"

void	init_all(t_info *p, char **av, char **env)
{
	p->fd1 = open(av[1], O_RDONLY);
	if (p->fd1 < 0)
		error("Error - infile");
	p->fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (p->fd2 < 0)
		error("Error - outfile");
	p->env = env;
	p->path = paths(p->env);
	p->cmd1_av = ft_split(av[2], ' ');
	p->cmd1 = get_cmd(p->path, p->cmd1_av[0]);
	p->cmd2_av = ft_split(av[3], ' ');
	p->cmd2 = get_cmd(p->path, p->cmd2_av[0]);
}

void	pipex(t_info *p)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		error("Error - fork_1");
	if (pid == 0)
		first_child(p);
	close(p->pipe[1]);
	pid = fork();
	if (pid < 0)
		error("Error - fork_2");
	if (pid == 0)
		second_child(p);
	close(p->pipe[0]);
	waitpid(p->pipe[0], &(p->fd_st), 0);
	waitpid(p->pipe[1], &(p->fd_st), 0);
}

int main(int ac, char **av, char **env)
{
	t_info	*p;

	if (ac == 5)
	{
		p = (t_info *)malloc(sizeof(t_info));
		if (pipe(p->pipe) == -1)
			error("Error - pipe");
		init_all(p, av, env);
		pipex(p);
		all_free(p);
	}
	else
		error("Error - input");
}
