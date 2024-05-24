/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:38:38 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/24 20:54:23 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	julia(t_fractol *fractol, double zx, double zy)
{
	double	tmp;
	int		it;

	it = 0;
	while (zx * zx + zy * zy < 4 && it < fractol->max)
	{
		tmp = zx * zx - zy * zy + fractol->jr;
		zy = 2 * zx * zy + fractol->ji;
		zx = tmp;
		it++;
	}
	return (it);
}

void	init_julia(t_fractol *fractol)
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
			c = scale_map(x, y, fractol);
			fractol->it = julia(fractol, c.real, c.i);
			if (fractol->it == fractol->max)
				my_mlx_pixel_put(fractol, x, y, 0x000000);
			else
				my_mlx_pixel_put(fractol, x, y, (0x00051020 * fractol->it));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}
