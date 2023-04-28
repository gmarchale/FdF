/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:54:12 by gmarchal          #+#    #+#             */
/*   Updated: 2023/04/28 14:59:56 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
//delete include 

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
