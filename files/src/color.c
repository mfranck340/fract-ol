/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:43:56 by ffierro-          #+#    #+#             */
/*   Updated: 2025/01/10 09:44:01 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	get_color(int i, int color)
{
	int	red;
	int	green;
	int	blue;

	red = (i * (color >> 16 & 0xFF) % 256);
	green = ((i * i * (color >> 8 & 0xFF)) % 256);
	blue = ((i * 17 + (color & 0xFF)) % 256);
	return ((red << 16) | (green << 8) | blue);
}

void	put_pixel_color(t_fractol *fractol, int x, int y, int color)
{
	char	*pixel_addr;

	pixel_addr = fractol->addr + (y * fractol->line_len + x
			* (fractol->bpp / 8));
	*(unsigned int *)pixel_addr = color;
}

void	put_color_to_pixel(int i, t_fractol *fractol)
{
	if (i == fractol->max_iter)
		put_pixel_color(fractol, fractol->x, fractol->y, 0x000000);
	else
		put_pixel_color(fractol, fractol->x, fractol->y,
			get_color(i, fractol->color));
}
