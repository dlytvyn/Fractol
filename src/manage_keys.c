/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:54:38 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/06/10 12:54:39 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook_add(int key, t_gen *gen)
{
	if (key == 19)
		gen->color = 2350;
	else if (key == 20)
		gen->color = 265;
	else if (key == 258)
	{
		if (gen->julia_mouse == 1)
			gen->julia_mouse = 0;
		else
			gen->julia_mouse = 1;
	}
	return (0);
}

int		key_hook(int key, t_gen *gen)
{
	if (key == 53)
		exit(1);
	else if (key == 69)
		gen->iterations_max++;
	else if (key == 78)
		gen->iterations_max--;
	else if (key == 123)
		gen->x1 += 30 / gen->zoom;
	else if (key == 124)
		gen->x1 -= 30 / gen->zoom;
	else if (key == 125)
		gen->y1 -= 30 / gen->zoom;
	else if (key == 126)
		gen->y1 += 30 / gen->zoom;
	else if (key == 49)
		fractal_initialization(gen);
	else if (key == 18)
		gen->color = 177216;
	key_hook_add(key, gen);
	fractal_calculation(gen);
	return (0);
}

void	zoom_in(int x, int y, t_gen *gen)
{
	gen->x2 = x;
	gen->y2 = y;
	gen->x1 = (x / gen->zoom + gen->x1) - ((gen->zoom * 1.3) / 2);
	gen->x1 += ((gen->zoom * 1.3) / 2) - (x / (gen->zoom * 1.3));
	gen->y1 = (y / gen->zoom + gen->y1) - ((gen->zoom * 1.3) / 2);
	gen->y1 += ((gen->zoom * 1.3) / 2) - (y / (gen->zoom * 1.3));
	gen->zoom *= 1.3;
	gen->iterations_max++;
}

void	zoom_out(t_gen *gen)
{
	gen->x1 = (gen->x2 / gen->zoom + gen->x1) - ((gen->zoom / 1.3) / 2);
	gen->x1 += ((gen->zoom / 1.3) / 2) - (gen->x2 / (gen->zoom / 1.3));
	gen->y1 = (gen->y2 / gen->zoom + gen->y1) - ((gen->zoom / 1.3) / 2);
	gen->y1 += ((gen->zoom / 1.3) / 2) - (gen->y2 / (gen->zoom / 1.3));
	gen->zoom /= 1.3;
	gen->iterations_max--;
}

int		mouse_hook(int mousecode, int x, int y, t_gen *gen)
{
	if (mousecode == 5 || mousecode == 1)
		zoom_in(x, y, gen);
	else if (mousecode == 4 || mousecode == 2)
		zoom_out(gen);
	fractal_calculation(gen);
	return (0);
}
