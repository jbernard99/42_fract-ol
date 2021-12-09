/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:58:25 by jbernard          #+#    #+#             */
/*   Updated: 2021/12/09 11:39:22 by jbernard         ###   ########.fr       */
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

t_fractal	init_fractal(unsigned int max_iter)
{
	t_fractal	fractal;

	fractal.c = init_complex();
	fractal.curr_iter = 0;
	fractal.max_iter = max_iter;
	return (fractal);
}

int	draw_fractal(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			if (data->type == 0)
				data->f.curr_iter = mandelbrot(data->f, data->s, x, y);
			else if (data->type == 1)
				data->f.curr_iter = julia(data->f, data->s, x, y);
			else if (data->type == 2)
				data->f.curr_iter = burning_ship(data->f, data->s, x, y);
			put_fractal_pixels(data->mlx, data->f, x, y);
			y++;
		}
		x++;
	}
	return (1);
}
