/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:25:29 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/10 18:25:32 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinates	ft_isometric(int x, int y, t_coordinates *coordinates,
			t_fdf_map *map)
{
	t_coordinates	transformed_coord;

	transformed_coord.y = (coordinates->x - map->parsed_map[x][y]) / sqrt(2);
	transformed_coord.x = ((coordinates->x + 2 * coordinates->y
				+ map->parsed_map[x][y]) / sqrt(6));
	return (transformed_coord);
}

t_coordinates	ratio(int x, int y, t_fdf_map *map)
{
	t_coordinates	new_coord;
	int				ratio;

	ratio = 1000 / (map->column_len + map->row_len);
	new_coord.x = (x * ratio) + 510;
	new_coord.y = (y * ratio) + 610;
	new_coord = ft_isometric(x, y, &new_coord, map);
	return (new_coord);
}

void	link_map_points(t_image_data *img, t_fdf_map *map)
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
				draw_line(img, ratio(res.x, res.y, map),
					ratio(res.x, res.y + 1, map));
			if (matrix.x < map->row_len - 1)
				draw_line(img, ratio(res.x, res.y, map),
					ratio(res.x + 1, res.y, map));
			matrix.x++;
		}
		matrix.y++;
	}
}
