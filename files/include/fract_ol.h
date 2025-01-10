/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:18:25 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 21:18:27 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define MSG_USAGE "Usage:\t./fract_ol [mandelbrot / julia / nova]\n"

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

# define ESC_KEY 65307
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define SPACE_KEY 32
# define SHIFT_KEY 65505

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractol
{
	char	fract;
	char	lock;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		color;
	int		max_iter;
	double	zoom;
	int		x;
	int		y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	offset_x;
	double	offset_y;
}	t_fractol;

void	handle_events(t_fractol *fractol);
void	draw_fractal(t_fractol *fractol);
void	put_color_to_pixel(int i, t_fractol *fractol);
void	review_arrow_keys(int keycode, t_fractol *fractol);
void	recalculate_offset(int x, int y, double zoom_factor,
			t_fractol *fractol);
int		mousemove_event(int x, int y, t_fractol *fractol);
void	do_op_nova(t_fractol *fractol);

#endif
