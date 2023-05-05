/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:41:01 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/05 16:34:29 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_window(int keycode, t_display *display)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(display->mlx, display->img.img);
		mlx_destroy_window(display->mlx, display->window);
		exit(1);
	}
	return (0);
}

int	ft_close_window_cross(t_display *display)
{
	(void) display;
	exit(1);
}

void	ft_mlx_hooks(t_display *display)
{
	mlx_key_hook(display->window, ft_close_window, display);
	mlx_hook(display->window, DESTROY, 0, ft_close_window_cross, display);
}
