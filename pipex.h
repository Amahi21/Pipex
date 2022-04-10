#ifndef		PIPEX_H
# define	PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

typedef struct s_info
{
	int		infile;
	int		outfile;
	int		pipe[2];

	int		fd1;
	int		fd2;
	int		fd_st;

	char	**env;
	char	*cmd1;
	char	*cmd2;
	char	**cmd1_av;
	char	**cmd2_av;
	char	**path;
}	t_info;

// error.c
void	error(char *error);

// src.c
char	**paths(char **envp);
char	*get_cmd(char **path, char *cmd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *strB, const char *strA, size_t len);
size_t	ft_strlen(const char *str);

// out.c
void	out_2p(char **str);
void	out_1p(char *str);

// split.c
void			ft_free(char **a);
char			**ft_split(char const *s, char c);

// childs.c
void	first_child(t_info *p);
void	second_child(t_info *p);

// free.c
void	all_free(t_info *p);

#endif	// PIPEX_H