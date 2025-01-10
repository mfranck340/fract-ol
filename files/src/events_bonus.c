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
