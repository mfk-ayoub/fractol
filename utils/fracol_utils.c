/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracol_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:48:21 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/24 21:19:11 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

bool	_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool	is_space(char c)
{
	char	*str;

	str = "\t\n\v\f\r ";
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

int	sign(char s, int *i)
{
	int	sign;

	sign = 1;
	if (s == '-' || s == '+')
	{
		if (s == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

double	ft_atof(const char *s)
{
	double	res;
	double	rat;
	int		i;
	int		sig;

	sig = 1;
	i = 0;
	rat = 0.1;
	res = 0.0;
	while (is_space(s[i]))
		i++;
	sig = sign(s[i], &i);
	while (_isdigit(s[i]))
		res = res * 10 + (s[i++] - '0');
	if (s[i] == '.')
	{
		i++;
		while (_isdigit(s[i]))
		{
			res += rat * (s[i] - '0');
			rat *= 0.1;
			i++;
		}
	}
	return (res * sig);
}
