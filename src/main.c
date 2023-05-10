/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <gmarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:54:12 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/10 18:28:43 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	init_mlx(t_display *display, t_image_data *img)
{
	display->mlx = mlx_init();
	if (!display->mlx)
		exit(1);
	display->window = mlx_new_window(display->mlx, 1920, 1080, "FDF");
	display->img.img = mlx_new_image(display->mlx, 1920, 1080);
	img->address = mlx_get_data_addr(display->img.img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

void	init_tab_parsing(char **argv, int fd, t_fdf_map *map,
		t_list *parsing_list)
{
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	parsing_list = convert_map_to_list(fd);
	*map = create_parsed_map(parsing_list);
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
	arg_error(argc, argv);
	init_tab_parsing(argv, fd, &map, &parsing_list);
	init_mlx(&display, &img);
	link_map_points(&img, &map);
	mlx_put_image_to_window(display.mlx, display.window,
		display.img.img, 0, 0);
	ft_mlx_hooks(&display);
	mlx_loop(display.mlx);
	return (1);
}
