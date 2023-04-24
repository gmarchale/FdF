/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:54:12 by gmarchal          #+#    #+#             */
/*   Updated: 2023/04/24 15:02:27 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
//delete include 

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
*/

/*
int	free_tab(char **tab)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (tab[i])
	{
		if (*tab[i] != '\n')
			c++;
		free(tab[i++]);
	}
	free(tab);
	return (c);
}

static int	get_height(int *h, char *file_path)
{
	int		fd;
	char	*line;

	*h = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_printf("ERROR : Wrong map dimensions."));
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		*h += 1;
	}
	close(fd);
	return (0);
}

static int	get_width(int w, int fd)
{
	char	*line;
	char	**tabline;

	line = get_next_line(fd);
	while (line)
	{
		tabline = ft_split(line, ' ');
		if (!tabline)
			return (ft_printf("ERROR : Split failed."));
		if (!w)
			w = free_tab(tabline);
		else
		{
			if (free_tab(tabline) != w)
			{
				close(fd);
				free(line);
				return (ft_printf("ERROR : Wrong map dimensions."));
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (w);
}

static int	get_dimensions(t_matrix *matrix, char *path_file)
{
	int w;
	int fd;

	w = 0;
	fd = 0;
	matrix->angle = 0.785398; // pq???
	fd = open(path_file, O_RDONLY);
	if (fd < 0)
		return(ft_printf("ERROR : failed to open file"));
	matrix->w = get_width(w, fd);
	close(fd);
	if (matrix->w <= 0)
		return (1);
	get_height(&matrix->h, path_file);
	if (matrix->h <= 0)
		return (1);
	return (0);
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

/*
int	main(int argc, char **argv)
{
	t_map	map;

	if (ac == 2)
	{
		map = get_map(argv[1]);
	}
	else
		ft_printf("Error: need 1 argument");
	return (0);
}
*/

void	draw_line(t_data *img, int x1, int y1, int x2, int y2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	double	ex;
	double	ey;
	double	e10;
	double	e01;
	double	e;

	x = x1;
	y = y1;
	ex = x1;
	ey = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	e = 0.0;
	e10 = (double)dy / dx;
	e01 = -1.0;
	printf("dy = %d, dx = %d, e10 = %f\n", dy, dx, e10);
	while (x < x2 && y < y2)
	{
		my_mlx_pixel_put(img, x, y, 0x00FF0000);
		e += e10;
		if (e  >= 0.5)
		{
			y++;
			e += e01; //e = e - 1;
		}
		x++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	double	x1 = 0;
	double	y1 = 0;
	double width = 2000;
	double height = 1000;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "Hello world!");
	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_line(&img, x1, y1, width, height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

