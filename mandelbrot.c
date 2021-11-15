/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:47:52 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/15 15:31:27 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

unsigned int	mandelbrot(t_fractal f, t_scale s, unsigned int x, unsigned int y)
{
	long double temp;
	f.complex.c_real = s.min_x + (s.max_x - s.min_x) * x / WIDTH;
	f.complex.c_imaginary = s.min_y + (s.max_y - s.min_y) * y / HEIGHT;
	f.complex.z_real = 0;
	f.complex.z_imaginary = 0;
	f.curr_iter = 0;

	while ((f.complex.z_real * f.complex.z_real + f.complex.z_imaginary * f.complex.z_imaginary < 4)
		&& (f.curr_iter < f.max_iter))
	{
		temp = f.complex.z_real * f.complex.z_real - f.complex.z_imaginary * f.complex.z_imaginary + f.complex.c_real;
		f.complex.z_imaginary = 2 * f.complex.z_real * f.complex.z_imaginary + f.complex.c_imaginary;
		f.complex.z_real = temp;
		f.curr_iter++;
	}
	return (f.curr_iter);
}