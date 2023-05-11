/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:26:27 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/11 17:11:16 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <math.h>
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

typedef struct s_coordinates
{
	int	x;
	int	y;
}	t_coordinates;

typedef struct s_map
{
	int		width;
	int		height;
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
void			free_tab(char **tab);
size_t			ft_strarray_len(char **array);
void			*my_malloc(size_t size);
void			ft_free_split(char **split_line);

//parsing.c
t_list			*convert_map_to_list(int map_fd);
int				*parse_line(t_list *parsing_list);
void			parse_all_lines(char *tmp, t_fdf_map *map,
					t_list *parsing_list, char **split_line);
t_fdf_map		create_parsed_map(t_list *parsing_list);

//checks.c
int				get_height(char *path_file);
int				get_width(char *path_file);
int				check_line(char *line);
int				check_map(char *path_file, t_map *map);

//mapping.c
void			draw_line_down(t_image_data *img,
					t_coordinates origin, t_coordinates end);
void			draw_line_up(t_image_data *img,
					t_coordinates origin, t_coordinates end);
void			draw_line(t_image_data *img,
					t_coordinates origin, t_coordinates end);

//hooks.c
int				close_window(int keycode, t_display *display);
int				close_window_cross(t_display *display);
void			ft_mlx_hooks(t_display *display);

//draw.c
t_coordinates	ft_isometric(int x, int y, t_coordinates *coordinates,
					t_fdf_map *map);
t_coordinates	ratio(int x, int y, t_fdf_map *map);
void			link_map_points(t_image_data *img, t_fdf_map *map);

#endif
