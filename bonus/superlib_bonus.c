/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superlib_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:44:39 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/24 21:11:31 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	lenght;

	lenght = 0;
	while (str[lenght] != '\0')
	{
		lenght++;
	}
	return (lenght);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	ssize_t	byte;

	byte = write(fd, s, ft_strlen(s));
	(void)byte;
}

void	_putcolor(char color)
{
	if (color == 'r')
		ft_putstr_fd("\033[1;31m", 1);
	else if (color == 'g')
		ft_putstr_fd("\033[1;32m", 1);
	else if (color == 'b')
		ft_putstr_fd("\033[1;34m", 1);
	else
		ft_putstr_fd("\033[0m", 1);
}

void	_error(int flag)
{
	if (flag == 0)
	{
		_putcolor('r');
		ft_putstr_fd("╭──── Syntax Error try : \n", STDERR_FILENO);
		ft_putstr_fd("╰─>\t\t\033[0m  [1] ./fractol m --[mandelbrot]\n",
			STDERR_FILENO);
		ft_putstr_fd("\t\t  [2] ./fractol j real_part and img_part --[julia]\n",
			STDERR_FILENO);
		ft_putstr_fd("\t\t  [3] ./fractol b --[Burning_Ship] \n",
			STDERR_FILENO);
		ft_putstr_fd("\t\t  [4] ./fractol t --[tricorn_set] \n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (flag == 1)
	{
		_putcolor('r');
		ft_putstr_fd("╭──── Syntax Error try : \n", STDERR_FILENO);
		ft_putstr_fd("╰─>\t\t\033[0m  [2] ./fractol", STDERR_FILENO);
		ft_putstr_fd("J real_part and img_part --[julia]\n", STDERR_FILENO);
	}
}
