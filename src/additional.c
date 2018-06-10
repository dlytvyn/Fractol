/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:54:55 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/06/10 12:54:56 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	put_pxl_to_img(t_gen *data, int x, int y, int color)
{
	if (data->x < SIZE && data->y < SIZE)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->image_ptr + 4 * SIZE * y + x * 4,
				&color, sizeof(int));
	}
}

void	put_text(t_gen *data)
{
	char	*num;

	num = ft_itoa(data->iterations_max);
	mlx_string_put(data->mlx, data->window, 10, 10, 0xFFFFFF, "iterations : ");
	mlx_string_put(data->mlx, data->window, 140, 10, 0xFFFFFF, num);
	ft_strdel(&num);
}
