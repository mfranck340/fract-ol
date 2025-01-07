
#include "../include/fract_ol.h"

int close_window(t_fractol *fractol)
{
    mlx_destroy_image(fractol->mlx, fractol->img);
    mlx_destroy_window(fractol->mlx, fractol->win);
    mlx_destroy_display(fractol->mlx);
    free(fractol);
    exit(0);
}

int key_hook(int keycode, t_fractol *fractol)
{
    if (keycode == ESC_KEY)
        close_window(fractol);
    else if (keycode == UP_KEY)
        close_window(fractol);
    return (0);
}



void handle_events(t_fractol *fractol)
{
    mlx_key_hook(fractol->win, key_hook, fractol);
    mlx_hook(fractol->win, 17, 0, close_window, fractol);
}
