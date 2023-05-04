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

int	get_len(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int	*fill_matrix(char **split_line)
{
	int	i;
	int	j;
	int	*row;

	row = malloc(get_len(line) * sizeof(int));
	while (split_line[i])
	{

	}
}

char	**get_line(char *path_file)
{
	int	i;
	int	j;
	int	fd;
	char	*line;
	char	**tab;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		free(line); // free a chaque fois ?
		fill_matrix(tab);
		line = get_next_line(fd);
	}
	free(line);
	return (tab);
}

char	**get_line2222(char *path_file)
{
	int	i;
	int	j;
	int	fd;
	char	*line;
	char	**tab;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	int	width = get_widthi(path_file);
	int	height = get_height(path_file);
	tab = char	**
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		free(line); // free a chaque fois ?
		line = get_next_line(fd);
	}
	//int k = 0;
	printf("%s", line);
	free(line);
	/*
	i = 0;
	j = 0;
	ft_printf("\n\n\n");
	while (j < get_width(path_file))
	{
		i = 0;
		while (i < get_height(path_file))
		{
			//ft_printf("tab[%d][%d] = %d\n", j, i, ft_atoi(&tab[j][i]));
			ft_printf("%d ", ft_atoi(&tab[j][i]));
			i++;
		}
		ft_printf("\n");
		j++;
	}
	*/
	return (tab);
}

int	**get_tableau(char **split_line, char *path_file)
{
	int	i;
	int	j;
	int	*line;
	int	width;
	int	height;

	i = 0;
	j = 0;
}

t_dot	**get_matrix(char **tab, char *path_file)
{
	int		i;
	int		j;
	int		width;
	int		height;
	t_dot	**matrix;

	i = 0;
	j = 0;
	width = get_width(path_file);
	height = get_height(path_file);
	matrix = (t_dot **) malloc(height * sizeof(t_dot *));
	while (i < height)
	{
		matrix[i] = (t_dot *) malloc(width * sizeof(t_dot));
		i++;
	}
	i = 0;
	while (j < width)
	{
		ft_printf("AAA i = %d, j = %d\n");
		i = 0;
		while (i < height)
		{
			ft_printf("BBB i = %d, j = %d\n");
			matrix[j][i].x = j;
			matrix[j][i].y = i;
			matrix[j][i].z = ft_atoi(&tab[j][i]);
			ft_printf("CCC matrix[j][i] = %d ", matrix[j][i].z); //print
			i++;
		}
		j++;
		ft_printf("\n");
	}
	/*
	tab = NULL;
	ft_printf("%d\n", width);
	ft_printf("%d\n", height);
	while (j < width)
	{
		i = 0;
		ft_printf("TEST DDD");
		while (i < height)
		{
			ft_printf("j = %d, i = %d\n", j, i);
			i++;
		}
		j++;
	}
	*/
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
	t_dot	**matrix;

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
	//matrix = get_matrix(salut_test, argv[1]);
	matrix = NULL;
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
