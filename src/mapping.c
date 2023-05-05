#include "fdf.h"

void	my_mlx_pixel_put(t_image_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_image_data *img, t_coordinates origin, t_coordinates end)
{
	t_coordinates	dot;
	double	slope;
	double	e;

	dot.x = origin.x;
	dot.y = origin.y;
	e = 0.0;
	slope = (double)(end.y - origin.y) / (end.x - origin.x);
	while (dot.x < end.x && dot.y < end.y)
	{
		my_mlx_pixel_put(img, dot.x, dot.y, 0x00FF0000);
		e += slope;
		if (e >= 0.5)
		{
			dot.y++;
			e += -1;
		}
		dot.x++;
	}
}
