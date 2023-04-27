/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:26:27 by gmarchal          #+#    #+#             */
/*   Updated: 2023/04/27 16:22:45 by gmarchal         ###   ########.fr       */
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
	MOUSE_WHEEL_LEFT = 7
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
	int		width;
	int		height;
	double	angle;
}				t_map;

void	draw_line(t_data *img, int x1, int y1, int x2, int y2);

#endif
