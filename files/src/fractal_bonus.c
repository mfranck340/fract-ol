
#include "../include/fract_ol.h"

void do_op_nova(t_fractol *fractol)
{
    int i;
    double p_r, p_i, dp_r, dp_i;
	double resul_r, resul_i;
	double mod_squared;
	double a;
	i = 0;
	a = 0.5;
    fractol->z_r = (fractol->x - WIN_WIDTH / 2.0) * fractol->zoom / WIN_WIDTH + fractol->offset_x;
    fractol->z_i = (fractol->y - WIN_HEIGHT / 2.0) * fractol->zoom / WIN_HEIGHT + fractol->offset_y;
    while (i < fractol->max_iter && (fractol->z_r * fractol->z_r + fractol->z_i * fractol->z_i) < 4)
    {
        p_r = (fractol->z_r * fractol->z_r * fractol->z_r) - (3 * fractol->z_r * fractol->z_i * fractol->z_i) - 1;
        p_i = (3 * fractol->z_r * fractol->z_r * fractol->z_i) - (fractol->z_i * fractol->z_i * fractol->z_i);

        dp_r = (3 * fractol->z_r * fractol->z_r) - (3 * fractol->z_i * fractol->z_i);
        dp_i = 6 * fractol->z_r * fractol->z_i;

        mod_squared = dp_r * dp_r + dp_i * dp_i;
		if (mod_squared < 1e-12) break;


		resul_r = fractol->z_r - a * ((p_r * dp_r + p_i * dp_i) / mod_squared) + fractol->c_r;
		resul_i = fractol->z_i - a * ((p_i * dp_r - p_r * dp_i) / mod_squared) + fractol->c_i;

		fractol->z_r = resul_r;
		fractol->z_i = resul_i;
        i++;
    }
    put_color_to_pixel(i, fractol);
}
