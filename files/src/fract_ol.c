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

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
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

int main()
{
    void *mlx;
    void *win;

	ft_printf("Hello World\n");
    // Inicia la conexión con el servidor X y crea una ventana
    mlx = mlx_init();
    win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Cuadrado en el Centro");

	ft_printf("Ventana creada\n");
    // Calcula las coordenadas del centro para el cuadrado
    int x_start = (WIN_WIDTH - SQUARE_SIZE) / 2;
    int y_start = (WIN_HEIGHT - SQUARE_SIZE) / 2;

	ft_printf("Coordenadas del centro calculadas\n");
    // Dibuja el cuadrado en el centro de la ventana
    draw_square(mlx, win, x_start, y_start, SQUARE_SIZE, 0x00FF00); // Color verde (0x00FF00)

	ft_printf("Cuadrado dibujado\n");
    // Mantén la ventana abierta hasta que el usuario la cierre
    mlx_loop(mlx);
	ft_printf("Fin del programa\n");
    return 0;
}
