/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:50:18 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/10 15:53:23 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_image_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	* (unsigned int*)dst = color;
}

static void	ft_delta_sign_check(int	*coord_sign, int *delta)
{
	*coord_sign = -1;
	*delta *= -1;
}

void	draw_line_down(t_image_data *img, t_coordinates origin,
				t_coordinates end)
{
	int				y_sign;
	int				decision_variable;
	t_coordinates	point;
	t_coordinates	delta;

	delta.x = end.x - origin.x;
	delta.y = end.y - origin.y;
	y_sign = 1;
	decision_variable = (2 * delta.y) - delta.x;
	point.y = origin.y;
	point.x = origin.x;
	if (delta.y < 0)
		ft_delta_sign_check(&y_sign, &delta.y);
	while (point.x <= end.x)
	{
		my_mlx_pixel_put(img, point.x, point.y, WHITE);
		if (decision_variable > 0)
		{
			point.y = point.y + y_sign;
			decision_variable = decision_variable + (2 * (delta.y - delta.x));
		}
		else
			decision_variable = decision_variable + 2 * delta.y;
		point.x++;
	}
}

void	draw_line_up(t_image_data *img, t_coordinates origin,
				t_coordinates end)
{
	int				x_sign;
	int				decision_variable;
	t_coordinates	delta;
	t_coordinates	point;

	delta.x = end.x - origin.x;
	delta.y = end.y - origin.y;
	x_sign = 1;
	decision_variable = (2 * delta.x) - delta.y;
	point.y = origin.y;
	point.x = origin.x;
	if (delta.x < 0)
		ft_delta_sign_check(&x_sign, &delta.x);
	while (point.y <= end.y)
	{
		my_mlx_pixel_put(img, point.x, point.y, WHITE);
		if (decision_variable > 0)
		{
			point.x = point.x + x_sign;
			decision_variable = decision_variable + (2 * (delta.x - delta.y));
		}
		else
			decision_variable = decision_variable + 2 * delta.x;
		point.y++;
	}
}

void	draw_line(t_image_data *img, t_coordinates origin, t_coordinates end)
{
	int	abs_y;
	int	abs_x;

	abs_y = abs(end.y - origin.y);
	abs_x = abs(end.x - origin.x);
	if (abs_y < abs_x)
	{
		if (origin.x > end.x)
			draw_line_down(img, end, origin);
		else
			draw_line_down(img, origin, end);
	}
	else
	{
		if (origin.y > end.y)
			draw_line_up(img, end, origin);
		else
			draw_line_up(img, origin, end);
	}
}
