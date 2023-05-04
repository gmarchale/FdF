/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <gmarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:54:12 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/04 18:41:33 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
//delete include 

void	ft_init_mlx(t_display *display, t_image_data *img)
{
	display->mlx = mlx_init();
	if (!display->mlx)
		exit(1);
	display->window = mlx_new_window(display->mlx, 1920, 1080, "FDF");
	display->img.img = mlx_new_image(display->mlx, 1920, 1080);
	img->address = mlx_get_data_addr(display->img.img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
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


void	ft_init_tab_parsing(char **argv, int fd, t_fdf_map *map,
		t_list *parsing_list)
{
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	parsing_list = ft_convert_map_to_list(fd);
	*map = ft_create_parsed_map(parsing_list);
	ft_lstclear(&parsing_list, &free);
}

int	main(int argc, char **argv)
{
	int				fd;
	t_list			parsing_list;
	t_fdf_map		map;
	t_display		display;
	t_image_data	img;

	fd = 0;
	if (argc == 2)
	{
		ft_init_tab_parsing(argv, fd, &map, &parsing_list);
		ft_init_mlx(&display, &img);
		//ft_link_map_points(&img, &map);
		mlx_put_image_to_window(display.mlx, display.window,
			display.img.img, 0, 0);
		//ft_mlx_hooks(&display);
		mlx_loop(display.mlx);
	}
	return (1);
}
/*
int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_map	map;
	t_dot	point_a;
	t_dot	point_b;

	point_a.x = 0;
	point_a.y = 0;
	point_b.x = 550;
	point_b.y = 250;
	(void)argc;
	(void)argv;

	arg_error(argc, argv);
	check_map(argv[1], &map);
	mlx = mlx_init(); //connecte au serveur graphique
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_line(&img, point_a, point_b);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/
