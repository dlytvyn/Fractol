/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:54:22 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/06/10 12:54:24 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractal_calculation(t_gen *gen)
{
	if (gen->iterations_max < 0)
		gen->iterations_max = 0;
	if (gen->fractal == 0)
		mandelbrot_threads(gen);
	else if (gen->fractal == 1)
		julia_threads(gen);
	else if (gen->fractal == 2)
		burningship_threads(gen);
	put_text(gen);
}

void	fractal_initialization(t_gen *gen)
{
	if (gen->fractal == 0)
		mandelbrot_initialization(gen);
	else if (gen->fractal == 1)
		julia_initialization(gen);
	else if (gen->fractal == 2)
		burningship_initialization(gen);
	fractal_calculation(gen);
}

void	init_window(t_gen *gen)
{
	gen->mlx = mlx_init();
	gen->window = mlx_new_window(gen->mlx, SIZE, SIZE, "FRACTOL");
	gen->image = mlx_new_image(gen->mlx, SIZE, SIZE);
	gen->image_ptr = mlx_get_data_addr(gen->image,
			&gen->bits_per_pixel, &gen->size_line, &gen->endian);
}

int		get_fractal(char **argv, t_gen *gen)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		gen->fractal = 0;
	else if (ft_strcmp(argv[1], "Julia") == 0)
		gen->fractal = 1;
	else if (ft_strcmp(argv[1], "Burningship") == 0)
		gen->fractal = 2;
	else
	{
		ft_putstr("Usage ./fractol [ \"Mandelbrot\", ");
		ft_putstr("\"Julia\", \"Burningship\" ]\n");
		return (0);
	}
	return (1);
}
