/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:58:25 by jbernard          #+#    #+#             */
/*   Updated: 2021/12/08 23:15:36 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_scale	init_scale(void)
{
	t_scale	scale;

	scale.min_x = -2;
	scale.max_x = 2;
	scale.min_y = -2;
	scale.max_y = 2;
	return (scale);
}

t_complex	init_complex(void)
{
	t_complex	complex;

	complex.z_real = 0;
	complex.z_im = 0;
	complex.c_real = 0;
	complex.c_im = 0;
	return (complex);
}

t_colors	init_colors(void)
{
	t_colors	colors;

	colors.R = 0;
	colors.G = 0;
	colors.B = 0;
	return (colors);
}

t_fractal	init_fractal(unsigned int max_iter)
{
	t_fractal	fractal;

	fractal.c = init_complex();
	fractal.colors = init_colors();
	fractal.curr_iter = 0;
	fractal.max_iter = max_iter;
	return (fractal);
}

int	draw_fractal(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (data->type == 0)
				data->fractal.curr_iter = mandelbrot(data->fractal, data->scale, x, y);
			else if (data->type == 1)
				data->fractal.curr_iter = julia(data->fractal, data->scale, x, y);
			else if (data->type == 2)
				data->fractal.curr_iter = burning_ship(data->fractal, data->scale, x, y);
			put_fractal_pixels(data->mlx, data->fractal, x, y);
			y++;
		}
		x++;
	}
	return (1);
}
