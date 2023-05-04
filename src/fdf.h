/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:26:27 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/04 18:01:21 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define WIDTH 1000
# define HEIGHT 1000

enum e_keys {
	ESC			= 53,
	UP			= 126,
	DOWN		= 125,
	LEFT		= 123,
	RIGHT		= 124,
	ZOOM_IN		= 69,
	ZOOM_OUT	= 78,
	Z_UP		= 92,
	Z_DOWN		= 85,
	MOUSE_LEFT	= 1,
	MOUSE_RIGHT = 2,
	MOUSE_WHEEL_DOWN = 4,
	MOUSE_WHEEL_UP = 5,
	MOUSE_WHEEL_RIGHT = 6,
	MOUSE_WHEEL_LEFT = 7,
	DESTROY = 17
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_dot
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_dot;

typedef struct s_map
{
	int		width; // = columns
	int		height; // = rows
	double	angle;
}				t_map;

typedef struct s_fdf_map
{
	int	**parsed_map;
	int	row_len;
	int	column_len;
}			t_fdf_map;

typedef struct s_image_data
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image_data;

typedef struct s_display
{
	void			*mlx;
	void			*window;
	t_image_data	img;
}			t_display;

//utils.c
void	draw_line(t_data *img, t_dot point_a, t_dot point_b);
void	free_tab(char **tab);
size_t	ft_strarray_len(char **array);
void	*my_malloc(size_t size);
void	ft_free_split(char **split_line);

//parsing.c
int		get_height(char *path_file);
int		get_width(char *path_file);
t_list	*ft_convert_map_to_list(int map_fd);
int	*ft_parse_line(t_list *parsing_list);
void	ft_parse_all_lines(char *tmp, t_fdf_map *map,
		t_list *parsing_list, char **split_line);
t_fdf_map	ft_create_parsed_map(t_list *parsing_list);

//checks.c
int		check_line(char *line);
int		check_map(char *path_file, t_map *map);

//hooks.c
int	key_hook(int key, t_data *data);

#endif
