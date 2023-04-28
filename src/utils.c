#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_data *img, t_dot point_a, t_dot point_b)
{
	t_dot	dot;
	double	slope;
	double	e;

	dot.x = point_a.x;
	dot.y = point_a.y;
	e = 0.0;
	slope = (double)(point_b.y - point_a.y) / (point_b.x - point_a.x);
	while (dot.x < point_b.x && dot.y < point_b.y)
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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
