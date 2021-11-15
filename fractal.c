/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:58:25 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/15 15:31:15 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_scale	init_scale()
{
	t_scale scale;
	
	scale.min_x = -2;
	scale.max_x = 2;
	scale.min_y = -2;
	scale.max_y = 2;

	return (scale);
}

t_complex	init_complex()
{
	t_complex complex;

	complex.z_real = 0;
	complex.z_imaginary = 0;
	complex.c_real = 0;
	complex.c_imaginary = 0;

	return (complex);
}

t_fractal init_fractal(int max_iter)
{
	t_fractal fractal;

	fractal.complex = init_complex();
	fractal.curr_iter = 0;
	fractal.max_iter = max_iter;

	return (fractal);
}

int	draw_fractal(t_data data)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			data.fractal.curr_iter = mandelbrot(data.fractal, data.scale, x, y);
			put_fractal_pixels(data.mlx, data.fractal, x, y);
			y++;
		}
		x++;
	}
	return (1);
}