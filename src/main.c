/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:54:12 by gmarchal          #+#    #+#             */
/*   Updated: 2023/04/27 17:06:09 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
//delete include 

/*
t_map	*get_map(char	*path)
{
	int		fd;
	t_map	*res;
	char	*line;

	res = ft_map_init(); //fontion pas encore faite
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_perror(path);
	line = get_next_line(fd);
	while (line && line[0] && line[0] != '\n')
	{
		ft_add_line(res, line);
		line = get_next_line(fd);
		++res->height;
	}
	close(fd);
	res->ratio = (double)res->height / 10.0 + (res->height < 10);
	ft_faces_init(res);
	if (res->width < 2 || res->height < 2)
		ft_perror("invalid map");
	if (!res->max)
		res->max = 1;
	return (res);
}

int main(int argc, char **argv)
{
	t_matrix *matrix;
	int dim;

	(void)argc;
	matrix = NULL;
	dim = get_dimensions(matrix, argv[1]);
	ft_printf("Height = %d\n Widht = %d\n Dimensions = %d\n", matrix->h, matrix->w, dim);
	return (0);
}

*/

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

//PARSING

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
	int	i;
	int	fd;
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
	while(line[i])
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
	int	fd;
	char *line;

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

void	arg_error(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		ft_printf("[ERROR]\nWrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	len = (int)ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".fdf", 4) != 0)
	{
		ft_printf("[ERROR]\nMap is not .fdf\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_map	map;

	double	x1 = 0;
	double	y1 = 0;
	double	x2 = 550;
	double	y2 = 250;
	(void)argc;
	(void)argv;

	arg_error(argc, argv);
	check_map(argv[1], &map);
	mlx = mlx_init(); //connecte au serveur graphique
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_line(&img, x1, y1, x2, y2);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
