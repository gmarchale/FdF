/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:53:04 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/04 17:55:06 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
