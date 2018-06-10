/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:55:18 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/06/10 12:55:19 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_julia(int x, int y, t_gen *gen)
{
	if (gen->fractal == 1 && gen->julia_mouse == 1)
	{
		gen->c_re = x * 2;
		gen->c_im = y * 2 - 800;
		fractal_calculation(gen);
	}
	return (0);
}

void	julia_initialization(t_gen *gen)
{
	gen->iterations_max = 50;
	gen->zoom = 200;
	gen->x1 = -2.0;
	gen->y1 = -1.9;
	gen->color = 265;
	gen->c_re = 0.285;
	gen->c_im = 0.01;
	gen->julia_mouse = 1;
}

void	julia_calculation(t_gen *gen)
{
	gen->z_re = gen->x / gen->zoom + gen->x1;
	gen->z_im = gen->y / gen->zoom + gen->y1;
	gen->iterations = 0;
	while (gen->z_re * gen->z_re + gen->z_im
			* gen->z_im < 4 && gen->iterations < gen->iterations_max)
	{
		gen->tmp = gen->z_re;
		gen->z_re = gen->z_re * gen->z_re -
			gen->z_im * gen->z_im - 0.8 + (gen->c_re / SIZE);
		gen->z_im = 2 * gen->z_im * gen->tmp + gen->c_im / SIZE;
		gen->iterations++;
	}
	if (gen->iterations == gen->iterations_max)
		put_pixel(gen, gen->x, gen->y, 0x000000);
	else
		put_pixel(gen, gen->x, gen->y, (gen->color * gen->iterations));
}

void	*julia(void *thread)
{
	double	tmp;
	t_gen	*gen;

	gen = (t_gen*)thread;
	gen->x = 0;
	tmp = gen->y;
	while (gen->x < SIZE)
	{
		gen->y = tmp;
		while (gen->y < gen->y_max)
		{
			julia_calculation(gen);
			gen->y++;
		}
		gen->x++;
	}
	return (thread);
}

void	julia_threads(t_gen *gen)
{
	t_gen		thread[8];
	pthread_t	thr[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&thread[i], (void*)gen, sizeof(t_gen));
		thread[i].y = 100 * i;
		thread[i].y_max = 100 * (i + 1);
		i++;
	}
	i = -1;
	while (++i < 8)
		pthread_create(&thr[i], NULL, julia, &thread[i]);
	while (--i >= 0)
		pthread_join(thr[i], NULL);
	mlx_put_image_to_window(gen->mlx, gen->window, gen->image, 0, 0);
}
