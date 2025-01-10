/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:44:19 by ffierro-          #+#    #+#             */
/*   Updated: 2025/01/10 09:44:22 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	change_color(t_fractol *fractol)
{
	if (fractol->color == 0x0D3180)
		fractol->color = 0x00FF80;
	else if (fractol->color == 0x00FF80)
		fractol->color = 0xFF3380;
	else if (fractol->color == 0xFF3380)
		fractol->color = 0x0F030F;
	else
		fractol->color = 0x0D3180;
}

void	review_arrow_keys(int keycode, t_fractol *fractol)
{
	if (keycode == UP_KEY)
		fractol->offset_y -= 0.1;
	else if (keycode == DOWN_KEY)
		fractol->offset_y += 0.1;
	else if (keycode == LEFT_KEY)
		fractol->offset_x -= 0.1;
	else if (keycode == RIGHT_KEY)
		fractol->offset_x += 0.1;
	else if (keycode == SHIFT_KEY)
		change_color(fractol);
	else if (keycode == SPACE_KEY)
	{
		if (fractol->lock == 'Y')
			fractol->lock = 'N';
		else
		{
			fractol->lock = 'Y';
			fractol->max_iter = 128;
		}
	}
	else
		return ;
	draw_fractal(fractol);
}

void	recalculate_offset(int x, int y, double zoom_factor, t_fractol *fractol)
{
	double	aux_x;
	double	aux_y;

	aux_x = (double)(x - WIN_WIDTH / 2) / WIN_WIDTH;
	aux_y = (double)(y - WIN_HEIGHT / 2) / WIN_HEIGHT;
	fractol->offset_x += aux_x * (fractol->zoom * zoom_factor - fractol->zoom);
	fractol->offset_y += aux_y * (fractol->zoom * zoom_factor - fractol->zoom);
	draw_fractal(fractol);
}

int	mousemove_event(int x, int y, t_fractol *fractol)
{
	if (fractol->lock == 'N')
	{
		if (fractol->fract == 'j')
		{
			fractol->c_r = 4 * ((double)x / WIN_WIDTH) - 2;
			fractol->c_i = 4 * ((double)y / WIN_HEIGHT) - 2;
			fractol->max_iter = 8;
			draw_fractal(fractol);
		}
		else if (fractol->fract == 'n')
		{
			fractol->c_r = 3.0 * ((double)x / WIN_WIDTH) - 1.5;
			fractol->max_iter = 4;
			draw_fractal(fractol);
		}
	}
	return (0);
}
