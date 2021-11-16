/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:03:00 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/15 23:12:28 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	zoom_in(t_data *data, int x, int y)
{
	long double mousex;
	long double mousey;

	mousex = x * (data->scale.max_x - data->scale.min_x) / WIDTH + data->scale.min_x;
	mousey = y * (data->scale.max_y - data->scale.min_y) / HEIGHT + data->scale.min_y;
	data->scale.max_x = data->scale.max_x / 1.1 + mousex * 0.1;
	data->scale.min_x = data->scale.min_x / 1.1 + mousex * 0.1;
	data->scale.max_y = data->scale.max_y / 1.1 + mousey * 0.1;
	data->scale.min_y = data->scale.min_y / 1.1 + mousey * 0.1;
	data->fractal.max_iter += 1;

	draw_fractal(*data);
	put_image(data->mlx);
}

void	zoom_out(t_data *data, int x, int y)
{
	long double mousex;
	long double mousey;

	mousex = x * (data->scale.max_x - data->scale.min_x) / WIDTH + data->scale.min_x;
	mousey = y * (data->scale.max_y - data->scale.min_y) / HEIGHT + data->scale.min_y;
	if (data->scale.max_x <= 2)
		data->scale.max_x = data->scale.max_x * 1.1 - mousex * 0.1;
	if (data->scale.min_x >= -2)
		data->scale.min_x = data->scale.min_x * 1.1 - mousex * 0.1;
	if (data->scale.max_y <= 2)
		data->scale.max_y = data->scale.max_y * 1.1 - mousey * 0.1;
	if (data->scale.min_y >= 2)
		data->scale.min_y = data->scale.min_y * 1.1 - mousex * 0.1;

	if (data->fractal.max_iter > 6)
		data->fractal.max_iter -= 1;

	draw_fractal(*data);
	put_image(data->mlx);
}

void	set_starting_z(t_data *data, int x, int y)
{
	data->fractal.complex.z_real = (double)x / WIDTH * 0.75;
	data->fractal.complex.z_imaginary = (double)y / HEIGHT * 0.54;
	printf("New Z set : \n    Real : %Lf\n    Imaginary : %Lf\n", data->fractal.complex.z_real, data->fractal.complex.z_imaginary);
	printf("C : \n    Real : %Lf\n    Imaginary : %Lf\n\n", data->fractal.complex.c_real, data->fractal.complex.c_imaginary);
}

int	mouse_event_manager(int button, int x, int y, t_data *data)
{
	if (button == 1)
		set_starting_z(data, x, y);
	else if (button == 4)
		zoom_out(data, x, y);
	else if (button == 5)
		zoom_in(data, x, y);
		
	draw_fractal(*data);
	put_image(data->mlx);
	return (1);
}