#include "pipex.h"

static size_t	words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

void	ft_free(char **a)
{
	int	i;

	i = 0;
	while (a[i] != NULL)
	{
		free(a[i]);
		i++;
	}
	free(a);
}

static int	len(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}


char	**ft_split(char const *s, char c)
{
	char	**a;
	size_t	i;
	size_t	j;
	size_t	z;

	a = (char **)malloc(sizeof(char *) * (words(s, c) + 1));
	if (!a)
		return (NULL);
	i = 0;
	z = 0;
	while (i < words(s, c))
	{
		a[i] = (char *)malloc(sizeof(char) * (len(s + z, c) + 1));
		if (a[i] == 0)
			ft_free(a);
		while (s[z] == c)
			z++;
		j = 0;
		while (s[z] != c && s[z] != '\0')
			a[i][j++] = s[z++];
		a[i++][j] = '\0';
	}
	a[i] = NULL;
	return (a);
}