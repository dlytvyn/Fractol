/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:58:46 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/14 16:00:12 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"
# define SIZE 800

typedef struct	s_gen
{
	void		*mlx;
	void		*window;
	void		*image;
	void		*image_ptr;
	int			endian;
	int			size_line;
	int			bits_per_pixel;
	int			fractal;
	int			color;
	int			julia_mouse;
	double		zoom;
	double		iterations_max;
	double		iterations;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		x;
	double		y;
	double		y_max;
	double		c_re;
	double		c_im;
	double		z_re;
	double		z_im;
	double		tmp;
}				t_gen;

int				key_hook(int keycode, t_gen *gen);
int				key_hook_add(int keycode, t_gen *gen);
void			zoom_in(int x, int y, t_gen *gen);
void			zoom_out(t_gen *gen);
int				mouse_hook(int mousecode, int x, int y, t_gen *gen);

void			mandelbrot_initialization(t_gen *gen);
void			mandelbrot_calculation(t_gen *gen);
void			*mandelbrot(void *tab);
void			mandelbrot_threads(t_gen *gen);

int				mouse_julia(int x, int y, t_gen *gen);
void			julia_initialization(t_gen *gen);
void			julia_calculation(t_gen *gen);
void			*julia(void *tab);
void			julia_threads(t_gen *gen);

void			burningship_initialization(t_gen *gen);
void			burningship_calculation(t_gen *gen);
void			*burningship(void *tab);
void			burningship_threads(t_gen *gen);

int				ft_close(void);
void			put_pxl_to_img(t_gen *gen, int x, int y, int color);
void			put_text(t_gen *gen);

void			fractal_calculation(t_gen *gen);
void			fractal_initialization(t_gen *gen);
void			mlx_win_init(t_gen *gen);
int				get_fractal(char **av, t_gen *gen);

#endif
