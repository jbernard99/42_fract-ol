/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:47:52 by jbernard          #+#    #+#             */
/*   Updated: 2021/12/08 13:35:45 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	mandelbrot(t_fractal f, t_scale s, unsigned int x, unsigned int y)
{
	long double temp;
	
	f.c.c_real = s.min_x + (s.max_x - s.min_x) * x / WIDTH;
	f.c.c_im = s.min_y + (s.max_y - s.min_y) * y / HEIGHT;
	f.curr_iter = 0;
	while (f.c.z_real*f.c.z_real + f.c.z_im*f.c.z_im < 4 && f.curr_iter < f.max_iter)
	{
		temp = f.c.z_real*f.c.z_real - f.c.z_im*f.c.z_im + f.c.c_real;
		f.c.z_im = 2 * f.c.z_real * f.c.z_im + f.c.c_im;
		f.c.z_real = temp;
		f.curr_iter++;
	}
	return (f.curr_iter);
}

unsigned int	julia(t_fractal f, t_scale s, unsigned int x, unsigned int y)
{
	long double temp;
	
	f.c.z_real = s.min_x + (s.max_x - s.min_x) * x / WIDTH;
	f.c.z_im = s.min_y + (s.max_y - s.min_y) * y / HEIGHT;
	f.curr_iter = 0;
	while (f.c.z_real*f.c.z_real + f.c.z_im*f.c.z_im < 4 && f.curr_iter < f.max_iter)
		{
			temp = f.c.z_real*f.c.z_real - f.c.z_im*f.c.z_im;
			f.c.z_im = 2 * f.c.z_real * f.c.z_im + f.c.c_im;
			f.c.z_real = temp + f.c.c_real;
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
	f.c.z_real = scaled_x;
	f.c.z_im = scaled_y;
	f.curr_iter = 0;
	while (f.c.z_real*f.c.z_real + f.c.z_im*f.c.z_im < 4
		&& f.curr_iter < f.max_iter){
			temp = f.c.z_real*f.c.z_real - f.c.z_im*f.c.z_im + scaled_x;
			f.c.z_im = fabsl(2 * f.c.z_real * f.c.z_im) + scaled_y;
			f.c.z_real = fabsl(temp);
			f.curr_iter++;
		}
	return (f.curr_iter);
}