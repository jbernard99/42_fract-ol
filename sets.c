/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:47:52 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/22 15:42:23 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

unsigned int	mandelbrot(t_fractal f, t_scale s, unsigned int x, unsigned int y)
{
	long double temp;
	
	f.complex.c_real = s.min_x + (s.max_x - s.min_x) * x / WIDTH;
	f.complex.c_imaginary = s.min_y + (s.max_y - s.min_y) * y / HEIGHT;
	f.curr_iter = 0;
	while ((pow(f.complex.z_real, 2) + pow(f.complex.z_imaginary, 2) < 4)
		&& (f.curr_iter < f.max_iter))
	{
		temp = pow(f.complex.z_real, 2) - pow(f.complex.z_imaginary, 2) + f.complex.c_real;
		f.complex.z_imaginary = 2 * f.complex.z_real * f.complex.z_imaginary + f.complex.c_imaginary;
		f.complex.z_real = temp;
		f.curr_iter++;
	}
	return (f.curr_iter);
}

unsigned int	julia(t_fractal f, t_scale s, unsigned int x, unsigned int y)
{
	long double temp;
	
	f.complex.z_real = s.min_x + (s.max_x - s.min_x) * x / WIDTH;
	f.complex.z_imaginary = s.min_y + (s.max_y - s.min_y) * y / HEIGHT;
	f.curr_iter = 0;
	while ((pow(f.complex.z_real, 2) + pow(f.complex.z_imaginary, 2) < 4) 
		&& f.curr_iter < f.max_iter){
			temp = pow(f.complex.z_real, 2) - pow(f.complex.z_imaginary, 2);
			f.complex.z_imaginary = 2 * f.complex.z_real * f.complex.z_imaginary + f.complex.c_imaginary;
			f.complex.z_real = temp + f.complex.c_real;
			f.curr_iter++;
		}
	return (f.curr_iter);
}

unsigned int	burning_ship(t_fractal f, t_scale s, unsigned int x, unsigned int y)
{
	long double temp;
	long double scaled_x;
	long double scaled_y;

	scaled_x = s.min_x + (s.max_x - s.min_x) * x / WIDTH;
	scaled_y = s.min_y + (s.max_y - s.min_y) * y / HEIGHT;
	f.complex.z_real = scaled_x;
	f.complex.z_imaginary = scaled_y;
	f.curr_iter = 0;
	while (pow(f.complex.z_real, 2) + pow(f.complex.z_imaginary, 2) < 4
		&& f.curr_iter < f.max_iter){
			temp = pow(f.complex.z_real, 2) - pow(f.complex.z_imaginary, 2) + scaled_x;
			f.complex.z_imaginary = fabsl(2 * f.complex.z_real * f.complex.z_imaginary) + scaled_y;
			f.complex.z_real = fabsl(temp);
			f.curr_iter++;
		}
	return (f.curr_iter);
}