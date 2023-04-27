#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_data *img, int x1, int y1, int x2, int y2)
{
	t_dot	dot;
	double	slope;
	double	e;

	dot.x = x1;
	dot.y = y1;
	e = 0.0;
	slope = (double)(y2 - y1) / (x2 - x1);
	while (dot.x < x2 && dot.y < y2)
	{
		my_mlx_pixel_put(img, dot.x, dot.y, 0x00FF0000);
		e += slope;
		if (e  >= 0.5)
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
