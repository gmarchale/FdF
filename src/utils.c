#include "fdf.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
size_t	ft_strarray_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	*my_malloc(size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	if (tmp == NULL)
	{
		exit(1);
	}
	return (tmp);
}

void	ft_free_split(char **split_line)
{
	int	j;

	j = 0;
	while (split_line[j])
	{
		free(split_line[j]);
		j++;
	}
	free(split_line);
}
