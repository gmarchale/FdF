/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <gmarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:54:12 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/05 16:23:51 by gmarchal         ###   ########.fr       */
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
/*
t_coordinates	ft_ratio(int x, int y, t_fdf_map *map)
{
	t_coordinates	new_coord;
	int				ratio;

	ratio = 1000 / (map->column_len + map->row_len);
	new_coord.x = (x * ratio) + 510;
	new_coord.y = (y * ratio) + 610;
	new_coord = ft_isometric(x, y, &new_coord, map);
	return (new_coord);
}

void	ft_link_map_points(t_image_data *img, t_fdf_map *map)
{
	t_coordinates	matrix;
	t_coordinates	res;

	matrix.y = 0;
	while (matrix.y < map->column_len)
	{
		matrix.x = 0;
		while (matrix.x < map->row_len)
		{
			res = matrix;
			if (matrix.y < map->column_len - 1)
				draw_line(img, ft_ratio(res.x, res.y, map),
					ft_ratio(res.x, res.y + 1, map));
			if (matrix.x < map->row_len - 1)
				draw_line(img, ft_ratio(res.x, res.y, map),
					ft_ratio(res.x + 1, res.y, map));
			matrix.x++;
		}
		matrix.y++;
	}
}
*/
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
		ft_printf("%d\n", map.parsed_map[2][2]);
		ft_init_mlx(&display, &img);
		//ft_link_map_points(&img, &map);
		mlx_put_image_to_window(display.mlx, display.window,
			display.img.img, 0, 0);
		ft_mlx_hooks(&display);
		mlx_loop(display.mlx);
	}
	return (1);
}
