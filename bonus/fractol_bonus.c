/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:54:22 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/24 21:11:00 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	ft_isdigit(int index)
{
	if (('0' <= index && '9' >= index) || '.' == index)
		return (1);
	return (0);
}

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 2;
	(void)ac;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '-' || av[i][0] == '+' || av[i][0] == '.')
		{
			if (!av[i][1])
				return (1);
			else
				j++;
		}
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	call_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		exit(EXIT_FAILURE);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fractol");
	if (!fractol->win)
		exit(EXIT_FAILURE);
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img.img)
		exit(EXIT_FAILURE);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
}

void	call_fractal(t_fractol *fractol, int ac, char **av)
{
	call_mlx(fractol);
	fractol->max = 100;
	fractol->zoom = 1.1;
	fractol->x = 0.0;
	fractol->y = 0.0;
	if ((ac == 2 && ft_strncmp(av[1], "m", sizeof(av[1])) == 0))
		init_mandelbrot(fractol);
	if ((ac == 4 && ft_strncmp(av[1], "j", sizeof(av[1])) == 0))
	{
		fractol->jr = ft_atof(av[2]);
		fractol->ji = ft_atof(av[3]);
		fractol->ji *= -1;
		init_julia(fractol);
	}
	if ((ac == 2 && ft_strncmp(av[1], "b", sizeof(av[1])) == 0))
		init_burning_ship(fractol);
	if ((ac == 2 && ft_strncmp(av[1], "t", sizeof(av[1])) == 0))
		init_tricon_set(fractol);
	mlx_hook(fractol->win, 17, 1L << 0, close_c, fractol);
	mlx_key_hook(fractol->win, key_handler, fractol);
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
	mlx_loop_hook(fractol->mlx, change_color, fractol);
	mlx_loop(fractol->mlx);
}

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	if (ac == 4)
	{
		(check_arg_dup('.', av[2]), check_arg_dup('.', av[3]));
	}
	if ((ac == 2 && ft_strncmp(av[1], "m", sizeof(av[1])) == 0) || (ac == 4
			&& ft_strncmp(av[1], "j", sizeof(av[1])) == 0) || (ac == 2
			&& ft_strncmp(av[1], "b", sizeof(av[1])) == 0) || (ac == 2
			&& ft_strncmp(av[1], "t", sizeof(av[1])) == 0))
	{
		if (check_arg(ac, av))
			(ft_putstr_fd(MSG, 2), exit(EXIT_FAILURE));
		fractol = malloc(sizeof(t_fractol));
		if (!fractol)
			return (EXIT_FAILURE);
		fractol->name = av[1];
		call_fractal(fractol, ac, av);
	}
	else
		handler_error(ac, av);
	return (EXIT_SUCCESS);
}
