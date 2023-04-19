/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:54:12 by gmarchal          #+#    #+#             */
/*   Updated: 2023/04/19 17:30:44 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
	/*
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
	*/
	return (res);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (ac == 2)
	{
		map = get_map(av[1]);
	}
	else
		ft_printf("Error: need 1 argument");
	return (0);
}

/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 520, 550, "Hello world!");
	img.img = mlx_new_image(mlx, 520, 550);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/
