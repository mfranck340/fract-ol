/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:45:10 by ffierro-          #+#    #+#             */
/*   Updated: 2025/01/10 09:45:13 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol);
	exit(0);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == ESC_KEY)
		close_window(fractol);
	review_arrow_keys(keycode, fractol);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	double	zoom_factor;

	zoom_factor = 1.2;
	if (button == SCROLL_UP)
	{
		fractol->zoom /= zoom_factor;
		recalculate_offset(x, y, zoom_factor, fractol);
	}
	else if (button == SCROLL_DOWN)
	{
		fractol->zoom *= zoom_factor;
		recalculate_offset(x, y, zoom_factor, fractol);
	}
	fractol->c_r += 0.1;
	draw_fractal(fractol);
	return (0);
}

void	handle_events(t_fractol *fractol)
{
	mlx_key_hook(fractol->win, key_hook, fractol);
	mlx_hook(fractol->win, 17, 0, close_window, fractol);
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
}
