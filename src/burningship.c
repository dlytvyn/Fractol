/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:55:08 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/06/10 12:55:09 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	burningship_initialization(t_gen *gen)
{
	gen->iterations_max = 50;
	gen->zoom = 220;
	gen->x1 = -2.2;
	gen->y1 = -2.5;
	gen->color = 265;
}

void	burningship_calculation(t_gen *gen)
{
	gen->c_re = gen->x / gen->zoom + gen->x1;
	gen->c_im = gen->y / gen->zoom + gen->y1;
	gen->z_re = 0;
	gen->z_im = 0;
	gen->iterations = 0;
	while (gen->z_re * gen->z_re + gen->z_im * gen->z_im < 4
			&& gen->iterations < gen->iterations_max)
	{
		gen->tmp = gen->z_re * gen->z_re - gen->z_im * gen->z_im + gen->c_re;
		gen->z_im = fabs(2 * gen->z_re * gen->z_im) + gen->c_im;
		gen->z_re = gen->tmp;
		gen->iterations++;
	}
	if (gen->iterations == gen->iterations_max)
		put_pxl_to_img(gen, gen->x, gen->y, 0x000000);
	else
		put_pxl_to_img(gen, gen->x, gen->y, (gen->color * gen->iterations));
}

void	*burningship(void *thread)
{
	double		tmp;
	t_gen		*gen;

	gen = (t_gen*)thread;
	gen->x = 0;
	tmp = gen->y;
	while (gen->x < SIZE)
	{
		gen->y = tmp;
		while (gen->y < gen->y_max)
		{
			burningship_calculation(gen);
			gen->y++;
		}
		gen->x++;
	}
	return (thread);
}

void	burningship_threads(t_gen *gen)
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
		pthread_create(&thr[i], NULL, burningship, &thread[i]);
	while (--i >= 0)
		pthread_join(thr[i], NULL);
	mlx_put_image_to_window(gen->mlx, gen->window, gen->image, 0, 0);
}
