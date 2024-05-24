/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:28:38 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/24 21:22:56 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	check_arg_dup(char c, char *str)
{
	int	i;
	int	target;

	i = 0;
	target = 0;
	while (str[i])
	{
		if (c == str[i])
			target++;
		i++;
	}
	if (target != 0 && target != 1)
	{
		ft_putstr_fd(MSG, 2);
		exit(EXIT_FAILURE);
	}
}

void	handler_error(int ac, char **av)
{
	if (ac == 1 || ac > 4)
		_error(0);
	else if (ft_strncmp(av[1], "j", sizeof(av[1])) == 0)
		_error(1);
	else
		_error(0);
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->img.addr + (y * fractol->img.line_length + x
			* (fractol->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
