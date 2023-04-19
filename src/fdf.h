/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:26:27 by gmarchal          #+#    #+#             */
/*   Updated: 2023/04/19 17:06:15 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "mlx.h"

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

typedef struct s_line {
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	ix;
	int	iy;
	int	i;
	int	color;
}	t_line;

typedef struct s_dot {
	float	x;
	float	y;
	float	z;
	int		color;
}	t_dot;

typedef struct s_map
{
	//t_vertice	*vert;
	//t_face		*faces;
	//t_vertice	*vert_last;
	//t_face		*faces_last;
	int			width;
	int			height;
}				t_map;

#endif
