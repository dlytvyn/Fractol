/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:54:22 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/06/10 12:54:24 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	t_gen	gen;

	if (argc == 2)
	{
		init_window(&gen);
		if ((get_fractal(argv, &gen)) == 0)
			return (0);
		fractal_initialization(&gen);
		mlx_hook(gen.window, 6, 1L < 6, mouse_julia, &gen);
		mlx_hook(gen.window, 17, 0L, ft_close, &gen);
		mlx_hook(gen.window, 2, 5, manage_keys, &gen);
		mlx_mouse_hook(gen.window, manage_mouse, &gen);
		mlx_loop(gen.mlx);
	}
	else
	{
		ft_putstr("Usage ./fractol [ \"Mandelbrot\", ");
		ft_putstr("\"Julia\", \"Burningship\" ]\n");
	}
	return (0);
}
