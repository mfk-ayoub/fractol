/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:03:34 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/24 20:53:52 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom_all(int key, t_fractol *fractol)
{
	if (key == 97)
		fractol->zoom *= 0.72;
	if (key == 115)
		fractol->zoom *= 1.28;
	if (key == 65361)
		fractol->x += 1.1 * fractol->zoom;
	if (key == 65363)
		fractol->x -= 1.1 * fractol->zoom;
	if (key == 65362)
		fractol->y += 1.1 * fractol->zoom;
	if (key == 65364)
		fractol->y -= 1.1 * fractol->zoom;
	if (key == 32)
	{
		fractol->zoom = 1.1;
		fractol->x = 0.0;
		fractol->y = 0.0;
	}
}

void	zoom_all_mouse(int x, int y, int key, t_fractol *fractol)
{
	t_complex	old;
	t_complex	new;

	old = scale_map(x, y, fractol);
	if (key == 4)
	{
		fractol->zoom *= 0.72;
		new = scale_map(x, y, fractol);
		fractol->x += old.real - new.real;
		fractol->y += old.i - new.i;
	}
	if (key == 5)
	{
		fractol->zoom *= 1.28;
		new = scale_map(x, y, fractol);
		fractol->x += old.real - new.real;
		fractol->y += old.i - new.i;
	}
}
