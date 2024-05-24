/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 01:49:06 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/24 21:11:49 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	tricon_set(double x, double y, t_fractol *fractol)
{
	double	tmp;
	int		it;
	double	zx;
	double	zy;

	zx = 0.0;
	zy = 0.0;
	it = 0;
	while (zx * zx + zy * zy < 4 && it < fractol->max)
	{
		tmp = zx * zx - zy * zy + x;
		zy = -2 * zx * zy + y;
		zx = tmp;
		it++;
	}
	return (it);
}

void	init_tricon_set(t_fractol *fractol)
{
	int			x;
	int			y;
	t_complex	c;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c = (scale_map(x, y, fractol));
			fractol->it = tricon_set(c.real, c.i, fractol);
			if (fractol->it == fractol->max)
				my_mlx_pixel_put(fractol, x, y, 0x000000);
			else
			{
				my_mlx_pixel_put(fractol, x, y, (0x00051020 * fractol->it));
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}
