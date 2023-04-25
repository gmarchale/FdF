/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:46:29 by gmarchal          #+#    #+#             */
/*   Updated: 2023/04/25 18:49:34 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:54:12 by gmarchal          #+#    #+#             */
/*   Updated: 2023/04/25 18:45:56 by gmarchal         ###   ########.fr       */
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



int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	//t_fdf_map	map;

	double	x1 = 0;
	double	y1 = 0;
	double	x2 = 550;
	double	y2 = 250;

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_line(&img, x1, y1, x2, y2);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
