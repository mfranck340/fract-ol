/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:44:55 by ffierro-          #+#    #+#             */
/*   Updated: 2025/01/10 09:44:59 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	do_op_mandelbrot(t_fractol *fractol)
{
	int		i;
	double	tmp;

	i = 0;
	fractol->z_r = 0;
	fractol->z_i = 0;
	fractol->c_r = (fractol->x - WIN_WIDTH / 2) * fractol->zoom / WIN_WIDTH
		+ fractol->offset_x;
	fractol->c_i = (fractol->y - WIN_HEIGHT / 2) * fractol->zoom / WIN_HEIGHT
		+ fractol->offset_y;
	while ((fractol->z_r * fractol->z_r) + (fractol->z_i * fractol->z_i) < 4
		&& i < fractol->max_iter)
	{
		tmp = 2 * fractol->z_r * fractol->z_i + fractol->c_i;
		fractol->z_r = fractol->z_r * fractol->z_r - fractol->z_i
			* fractol->z_i + fractol->c_r;
		fractol->z_i = tmp;
		i++;
	}
	put_color_to_pixel(i, fractol);
}

void	do_op_julia(t_fractol *fractol)
{
	int		i;
	double	tmp;

	i = 0;
	fractol->z_r = (fractol->x - WIN_WIDTH / 2) * fractol->zoom / WIN_WIDTH
		+ fractol->offset_x;
	fractol->z_i = (fractol->y - WIN_HEIGHT / 2) * fractol->zoom / WIN_HEIGHT
		+ fractol->offset_y;
	while ((fractol->z_r * fractol->z_r) + (fractol->z_i * fractol->z_i) < 4
		&& i < fractol->max_iter)
	{
		tmp = 2 * fractol->z_r * fractol->z_i + fractol->c_i;
		fractol->z_r = fractol->z_r * fractol->z_r - fractol->z_i
			* fractol->z_i + fractol->c_r;
		fractol->z_i = tmp;
		i++;
	}
	put_color_to_pixel(i, fractol);
}

void	draw_fractal(t_fractol *fractol)
{
	fractol->x = 0;
	while (fractol->x < WIN_WIDTH)
	{
		fractol->y = 0;
		while (fractol->y < WIN_HEIGHT)
		{
			if (fractol->fract == 'm')
				do_op_mandelbrot(fractol);
			else if (fractol->fract == 'j')
				do_op_julia(fractol);
			else
				do_op_nova(fractol);
			fractol->y++;
		}
		fractol->x++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	ft_printf("Press ESC to exit\n");
}
