/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:33:49 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/17 13:46:49 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	set_new_center(t_data *data, int x, int y)
{
	long double middle_x;
	long double middle_y;
	long double new_middle_x;
	long double new_middle_y;

	middle_x = (data->scale.min_x + data->scale.max_x) / 2;
	middle_y = (data->scale.min_y + data->scale.max_y) / 2;
	new_middle_x = x * (data->scale.max_x - data->scale.min_x) / WIDTH + data->scale.min_x;
	new_middle_y = y * (data->scale.max_y - data->scale.min_y) / HEIGHT + data->scale.min_y;
	
	x_movement = mouse_x - middle_x;
	y_movement = mouse_y - middle_y;
	
	data->scale.max_x += x_movement / 3;
	data->scale.min_x += x_movement / 3;
	data->scale.max_y += y_movement / 3;
	data->scale.min_y += y_movement / 3;
	
	printf("x : %d, y : %d\n", x, y);
	printf("max_x : %Lf, max_y : %Lf\n", data->scale.max_x, data->scale.max_y);
	printf("min_x : %Lf, min_y : %Lf\n", data->scale.min_x, data->scale.min_y);
	printf("mouse_x : %Lf, mouse_y : %Lf\n\n", mouse_x, mouse_y);
}

void	zoom_in(t_data *data, int x, int y)
{
	set_new_center(data, x, y);
	data->scale.max_x = data->scale.max_x / 1.1;
	data->scale.min_x = data->scale.min_x / 1.1;
	data->scale.max_y = data->scale.max_y / 1.1;
	data->scale.min_y = data->scale.min_y / 1.1;
	data->fractal.max_iter += 1;
}

void	zoom_out(t_data *data, int x, int y)
{
	set_new_center(data, x, y);
	data->scale.max_x = data->scale.max_x * 1.1;
	data->scale.min_x = data->scale.min_x * 1.1;
	data->scale.max_y = data->scale.max_y * 1.1;
	data->scale.min_y = data->scale.min_y * 1.1;
	if (data->fractal.max_iter > 1)
		data->fractal.max_iter -= 1;
}