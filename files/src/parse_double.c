/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:22:05 by ffierro-          #+#    #+#             */
/*   Updated: 2025/01/11 16:22:08 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	check_double(char *str)
{
	int	i;
	int	dot;

	dot = 0;
	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) || (str[i] == '.' && i > 0 && !dot))
		{
			if (str[i] == '.' && !dot)
				dot = !dot;
		}
		else
			return (0);
	}
	return (1);
}

double	to_double(char *str)
{
	double	integer_part;
	double	decimal_part;
	int		sign;

	if (str[0] == '-')
		sign = -1;
	else
		sign = 1;
	integer_part = ft_atoi(str) + 0.0;
	str = ft_strchr(str, '.');
	if (!str)
		return (integer_part);
	decimal_part = ft_atoi(str + 1) / (pow(10, ft_strlen(str + 1)));
	if (integer_part == 0 && sign == -1)
		return (-1 * (integer_part + decimal_part));
	return (integer_part + sign * decimal_part);
}

int	double_to_julia(t_fractol **fractol, char **argv)
{
	if (!check_double(argv[2]) || !check_double(argv[3]))
	{
		ft_printf("hola");
		free(*fractol);
		ft_printf(MSG_USAGE);
		return (0);
	}
	(*fractol)->c_r = to_double(argv[2]);
	(*fractol)->c_i = to_double(argv[3]);
	return (1);
}
