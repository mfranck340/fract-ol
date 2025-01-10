/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:44:41 by ffierro-          #+#    #+#             */
/*   Updated: 2025/01/10 09:44:44 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	function_nova(double *p, t_fractol *fractol)
{
	p[0] = (fractol->z_r * fractol->z_r * fractol->z_r) - (3 * fractol->z_r
			* fractol->z_i * fractol->z_i) - 1;
	p[1] = (3 * fractol->z_r * fractol->z_r * fractol->z_i) - (fractol->z_i
			* fractol->z_i * fractol->z_i);
}

void	derivative_nova(double *dp, t_fractol *fractol)
{
	dp[0] = (3 * fractol->z_r * fractol->z_r) - (3 * fractol->z_i
			* fractol->z_i);
	dp[1] = 6 * fractol->z_r * fractol->z_i;
}

void	update_nova(double *p, double *dp, double mod_squared,
	t_fractol *fractol)
{
	double	tmp;
	double	a;

	a = 1;
	tmp = fractol->z_i - a * ((p[1] * dp[0] - p[0] * dp[1]) / mod_squared)
		+ fractol->c_i;
	fractol->z_r = fractol->z_r - a * ((p[0] * dp[0] + p[1] * dp[1])
			/ mod_squared) + fractol->c_r;
	fractol->z_i = tmp;
}

void	do_op_nova(t_fractol *fractol)
{
	int		i;
	double	p[2];
	double	dp[2];
	double	mod_squared;

	i = 0;
	fractol->z_r = (fractol->x - WIN_WIDTH / 2.0) * fractol->zoom / WIN_WIDTH
		+ fractol->offset_x;
	fractol->z_i = (fractol->y - WIN_HEIGHT / 2.0) * fractol->zoom / WIN_HEIGHT
		+ fractol->offset_y;
	while (i < fractol->max_iter && (fractol->z_r * fractol->z_r + fractol->z_i
			* fractol->z_i) < 4)
	{
		function_nova(p, fractol);
		derivative_nova(dp, fractol);
		mod_squared = dp[0] * dp[0] + dp[1] * dp[1];
		if (mod_squared < 1e-12)
			break ;
		update_nova(p, dp, mod_squared, fractol);
		i++;
	}
	put_color_to_pixel(i, fractol);
}
