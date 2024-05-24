/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:48:47 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/24 21:21:51 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	free_and_exit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	free(fractol);
	_putcolor('b');
	ft_putstr_fd("\t\tProgram quit successfully ! \n", 2);
	_putcolor('d');
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractol *fractol)
{
	if (keycode == 65451)
		fractol->max += 10;
	if (keycode == XK_Escape)
		free_and_exit(fractol);
	if (!ft_strncmp(fractol->name, "j", sizeof(fractol->name)))
	{
		zoom_all(keycode, fractol);
		init_julia(fractol);
	}
	else if (!ft_strncmp(fractol->name, "m", sizeof(fractol->name)))
	{
		zoom_all(keycode, fractol);
		init_mandelbrot(fractol);
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "j", sizeof(fractol->name)))
	{
		zoom_all_mouse(x, y, keycode, fractol);
		init_julia(fractol);
	}
	else if (!ft_strncmp(fractol->name, "m", sizeof(fractol->name)))
	{
		zoom_all_mouse(x, y, keycode, fractol);
		init_mandelbrot(fractol);
	}
	return (0);
}

int	close_c(t_fractol *fractol)
{
	free_and_exit(fractol);
	return (0);
}
