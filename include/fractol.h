/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:56:53 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/05/24 20:57:22 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# define WIDTH 900
# define HEIGHT 900

# define BLACK 0x00001F
# define BLUE 0x0000FF
# define RED 0xFF0000

# define MSG "\t\t\033[1;31m Error arg is not a digit\033[0m\n"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_data	img;
	int		color;
	int		it;
	double	jr;
	double	ji;
	int		max;
	double	zoom;
	char	*name;
	double	x;
	double	y;

}			t_fractol;

typedef struct s_complex
{
	double	real;
	double	i;
}			t_complex;

void		my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);
void		init_mandelbrot(t_fractol *fractol);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
int			key_handler(int keycode, t_fractol *fractol);
void		_putcolor(char color);
void		_error(int flag);
void		shift_color(t_fractol *fractol, double x, double y);
int			change_color(t_fractol *fractol);
void		init_julia(t_fractol *fractol);
int			julia(t_fractol *fractol, double zx, double zy);
t_complex	scale_map(int x, int y, t_fractol *fractol);
void		my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);
void		free_and_exit(t_fractol *fractol);
int			close_c(t_fractol *fractol);
int			key_handler(int keycode, t_fractol *fractol);
int			mouse_hook(int keycode, int x, int y, t_fractol *fractol);
void		zoom_all(int key, t_fractol *fractol);
void		init_burning_ship(t_fractol *fractol);
double		ft_atof(const char *s);
void		zoom_all_mouse(int x, int y, int key, t_fractol *fractol);
void		init_tricon_set(t_fractol *fractol);
void		check_arg_dup(char c, char *str);
void		handler_error(int ac, char **av);
#endif