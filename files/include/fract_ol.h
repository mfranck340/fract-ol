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

# define WIN_WIDTH 1500
# define WIN_HEIGHT 600

# define ESC_KEY 65307
# define UP_KEY 65362
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractol
{
    void	*mlx;
    void	*win;
    void	*img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
    int		width;
    int		height;
    int		fract;
    int		color;
    int		max_iter;
    double	zoom;
    double	x1;
    double	y1;
    double	x2;
    double	y2;
    double	c_r;
    double	c_i;
    double	z_r;
    double	z_i;
    double	tmp;
}	t_fractol;

void handle_events(t_fractol *fractol);

#endif
