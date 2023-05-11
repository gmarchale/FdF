/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:41:01 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/11 16:16:33 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(int keycode, t_display *display)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(display->mlx, display->img.img);
		mlx_destroy_window(display->mlx, display->window);
		exit(0);
	}
	return (0);
}

int	close_window_cross(t_display *display)
{
	(void) display;
	exit(0);
}

void	ft_mlx_hooks(t_display *display)
{
	mlx_key_hook(display->window, close_window, display);
	mlx_hook(display->window, DESTROY, 0, close_window_cross, display);
}
