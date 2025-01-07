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

#define SQUARE_SIZE 100

void draw_square(void *mlx, void *win, int x_start, int y_start, int size, int color)
{
    for (int y = y_start; y < y_start + size; y++)
    {
        for (int x = x_start; x < x_start + size; x++)
        {
            mlx_pixel_put(mlx, win, x, y, color);
        }
    }
}

int init_fractol(t_fractol **fractol)
{
    (*fractol) = malloc(sizeof(t_fractol));
    if (!(*fractol))
        return (0);
    (*fractol)->mlx = mlx_init();
    (*fractol)->win = mlx_new_window((*fractol)->mlx, WIN_WIDTH, WIN_HEIGHT, "FRACT-OL");
    (*fractol)->img = mlx_new_image((*fractol)->mlx, WIN_WIDTH, WIN_HEIGHT);
    (*fractol)->addr = mlx_get_data_addr((*fractol)->img, &(*fractol)->bpp, &(*fractol)->line_len, &(*fractol)->endian);
    (*fractol)->width = WIN_WIDTH;
    (*fractol)->height = WIN_HEIGHT;
    (*fractol)->fract = 1;
    (*fractol)->color = 0x000000;
    (*fractol)->max_iter = 50;
    (*fractol)->zoom = 1;
    (*fractol)->x1 = -2.1;
    (*fractol)->y1 = -1.2;
    (*fractol)->x2 = 0.6;
    (*fractol)->y2 = 1.2;
    (*fractol)->c_r = 0;
    (*fractol)->c_i = 0;
    (*fractol)->z_r = 0;
    (*fractol)->z_i = 0;
    (*fractol)->tmp = 0;
    return (1);
}

int main()
{
    t_fractol *fractol;

    if (!init_fractol(&fractol))
        return (1);
    handle_events(fractol);
    mlx_loop(fractol->mlx);
    free(fractol);
    return 0;
}
