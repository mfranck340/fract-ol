/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:17:59 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 21:18:01 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	init_custom_fractol(t_fractol **fractol, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot\0", 11) == 0 && argc == 2)
	{
		(*fractol)->fract = 'm';
		(*fractol)->offset_x = -0.7;
		(*fractol)->offset_y = 0;
	}
	else if (ft_strncmp(argv[1], "julia\0", 6) == 0 && argc == 4)
	{
		(*fractol)->fract = 'j';
		if (!double_to_julia(fractol, argv))
			return (0);
	}
	else if (ft_strncmp(argv[1], "nova\0", 5) == 0 && argc == 2)
		(*fractol)->fract = 'n';
	else
	{
		free(*fractol);
		ft_printf(MSG_USAGE);
		return (0);
	}
	return (1);
}

int	init_fractol(t_fractol **fractol, int argc, char **argv)
{
	(*fractol) = malloc(sizeof(t_fractol));
	if (!(*fractol))
		return (0);
	(*fractol)->c_r = 0;
	(*fractol)->c_i = 0;
	(*fractol)->offset_x = 0;
	(*fractol)->offset_y = 0;
	if (!init_custom_fractol(fractol, argc, argv))
		return (0);
	(*fractol)->lock = 'Y';
	(*fractol)->mlx = mlx_init();
	(*fractol)->win = mlx_new_window((*fractol)->mlx, WIN_WIDTH, WIN_HEIGHT,
			"FRACT-OL");
	(*fractol)->img = mlx_new_image((*fractol)->mlx, WIN_WIDTH, WIN_HEIGHT);
	(*fractol)->addr = mlx_get_data_addr((*fractol)->img, &(*fractol)->bpp,
			&(*fractol)->line_len, &(*fractol)->endian);
	(*fractol)->color = 0x0D3180;
	(*fractol)->max_iter = MAX_ITER;
	(*fractol)->zoom = 3;
	(*fractol)->x = 0;
	(*fractol)->y = 0;
	(*fractol)->z_r = 0;
	(*fractol)->z_i = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc != 2 && argc != 4)
	{
		ft_printf(MSG_USAGE);
		return (1);
	}
	if (!init_fractol(&fractol, argc, argv))
		return (1);
	draw_fractal(fractol);
	handle_events(fractol);
	mlx_loop(fractol->mlx);
	free(fractol);
	return (0);
}
