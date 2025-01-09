
#include "../include/fract_ol.h"

int get_color(int i)
{
    int red;
    int green;
    int blue;

    // Fórmulas para colores psicodélicos
    red = (i * 13 % 256);                // Ciclo rápido y vibrante para el rojo
    green = ((i * i * 7) % 256);         // Variación no lineal para el verde
    blue = ((i * 17 + 128) % 256);       // Cambio rápido con desfase para el azul

    return ((red << 16) | (green << 8) | blue);
}

void put_pixel_color(t_fractol *fractol, int x, int y, int color)
{
	char *pixel_addr;

	pixel_addr = fractol->addr + (y * fractol->line_len + x * (fractol->bpp / 8));
	*(unsigned int*)pixel_addr = color;
}

void	put_color_to_pixel(int i, t_fractol *fractol)
{
	if (i == fractol->max_iter)
		put_pixel_color(fractol, fractol->x, fractol->y, 0x000000);
	else
		put_pixel_color(fractol, fractol->x, fractol->y, get_color(i));
}
