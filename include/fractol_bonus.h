/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:45:56 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/24 21:17:37 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "fractol.h"

void	shift_color(t_fractol *fractol, double x, double y);
int		change_color(t_fractol *fractol);

int		mouse_hook(int keycode, int x, int y, t_fractol *fractol);
void	init_burning_ship(t_fractol *fractol);
void	zoom_all_mouse(int x, int y, int key, t_fractol *fractol);
void	init_tricon_set(t_fractol *fractol);
#endif