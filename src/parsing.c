/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:39:16 by gmarchal          #+#    #+#             */
/*   Updated: 2023/04/27 17:42:21 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *path_file)
{
	int		count;
	int		fd;
	char	*tmp;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (-1); // to do : gerer error
	count = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp && count == 0)
			return (-1); // to do : gerer error
		if (!tmp)
			break ;
		count++;
		free(tmp);
	}
	close(fd);
	return (count);
}

int	get_width(char *path_file)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	tab = ft_split(line, ' ');
	free(line);
	i = 0;
	while (tab[i])
		i++;
	free_tab(tab);
	return (i);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == '\n')
			i++;
		else if ((line[i] == '+' || line[i] == '-') && ft_isdigit(line[i + 1]))
		{
			i++;
		}
		else
		{
			ft_printf("map unvalid: line[i] == %c\n", line[i]);
			return (-1);
		}
	}
	return (0);
}

int	check_map(char *path_file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (check_line(line) == -1)
			return (-1);
		line = get_next_line(fd);
	}
	map->height = get_height(path_file);
	map->width = get_width(path_file);
	return (0);
}
