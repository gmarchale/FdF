/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:54:12 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/02 15:31:19 by gmarchal         ###   ########.fr       */
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

char	**get_tableau(char *path_file)
{
	int	i;
	int	j;
	int	fd;
	char	*line;
	char	**tab;

	tab = NULL;
	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	j = 0;
	while (line)
	{
		tab = ft_split(line, ' ');
		free(line); // free a chaque fois ?
		line = get_next_line(fd);
	}
	free(line);
	return (tab);
}

t_dot	**get_matrix(char **tab)
{
	int		i;
	int		j;
	t_dot	**matrix;

	i = 0;
	j = 0;
	matrix = NULL;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			matrix[j][i].x = j;
			matrix[j][i].y = i;
			matrix[j][i].z = ft_atoi(&tab[j][i]);
			//ft_printf("%d ", matrix[j][i]); //print
			i++;
		}
		j++;
		//ft_printf("\n");
	}
	return (matrix);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_map	map;
	t_dot	point_a;
	t_dot	point_b;
	//t_dot	**matrix;

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
	char **salut_test;
	salut_test = get_tableau(argv[1]);
	//matrix = get_matrix(salut);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
