/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:43:25 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/24 21:16:04 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	shift_color(t_fractol *fractol, double x, double y)
{
	int		color;
	int		red;
	int		green;
	int		blue;
	char	*content;

	content = fractol->img.addr + (int)y * fractol->img.line_length + (int)x
		* (fractol->img.bits_per_pixel / 8);
	color = *(int *)content;
	if (0x0 == color)
		return ;
	red = (color & 0xFF0000) >> 16;
	green = (color & 0xFF00) >> 8;
	blue = (color & 0xFF);
	red = (red + 1) % 200;
	green = (green + 2) % 250;
	blue = (blue + 4) % 250;
	color = (red << 16) + (green << 8) + blue;
	*(int *)content = color;
}

int	change_color(t_fractol *fractol)
{
	double	i;
	double	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			shift_color(fractol, i, j);
			j++;
		}
		i++;
	}
	mlx_clear_window(fractol->mlx, fractol->win);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	return (0);
}
