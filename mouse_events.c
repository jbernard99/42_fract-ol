/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:03:00 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/23 16:27:15 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

// void	set_starting_z(t_data *data, int x, int y)
// {
// 	data->fractal.c.z_real = (double)x / WIDTH * 0.75;
// 	data->fractal.c.z_im = (double)y / HEIGHT * 0.54;
// 	printf("New Z set : \n    Real : %Lf\n    Imaginary : %Lf\n", data->fractal.c.z_real, data->fractal.c.z_im);
// 	printf("C : \n    Real : %Lf\n    Imaginary : %Lf\n\n", data->fractal.c.c_real, data->fractal.c.c_im);
// }

int	move_cursor(int x, int y, t_data *data)
{
	data->fractal.c.c_real = data->scale.min_x + (data->scale.max_x - data->scale.min_x) * x / WIDTH;
	data->fractal.c.c_im = data->scale.min_y + (data->scale.max_y - data->scale.min_y) * y / HEIGHT;
	draw_fractal(*data);
	put_image(data->mlx);
	return (1);
}

void	set_new_center(t_data *data, int x, int y)
{
	long double curr_middle_x;
	long double curr_middle_y;
	//long double x_movement;
	//long double y_movement;
	//long double scaled_x;
	(void)x;
	(void)y;

	curr_middle_x = (data->scale.max_x + data->scale.min_x) / 2;
	curr_middle_y = (data->scale.max_y + data->scale.min_y) / 2;

	printf("curr_middle_x : %Lf, curr_middle_y : %Lf\n", curr_middle_x, curr_middle_y);
	
	// data->scale.max_x += x_movement; /// 3;
	// data->scale.min_x += x_movement; /// 3;
	// data->scale.max_y += y_movement; /// 3;
	// data->scale.min_y += y_movement; /// 3;
}

void	zoom_in(t_data *data, int x, int y)
{
	set_new_center(data, x, y);
	// data->scale.max_x = data->scale.max_x / 1.1;
	// data->scale.min_x = data->scale.min_x / 1.1;
	// data->scale.max_y = data->scale.max_y / 1.1;
	// data->scale.min_y = data->scale.min_y / 1.1;
	data->fractal.max_iter += 1;
}

void	zoom_out(t_data *data, int x, int y)
{
	set_new_center(data, x, y);
	// data->scale.max_x = data->scale.max_x * 1.1;
	// data->scale.min_x = data->scale.min_x * 1.1;
	// data->scale.max_y = data->scale.max_y * 1.1;
	// data->scale.min_y = data->scale.min_y * 1.1;
	if (data->fractal.max_iter > 1)
		data->fractal.max_iter -= 1;
}