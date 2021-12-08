/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:03:00 by jbernard          #+#    #+#             */
/*   Updated: 2021/12/08 14:51:43 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	move_cursor(int x, int y, t_data *data)
{
	data->fractal.c.c_real = data->scale.min_x + (data->scale.max_x - data->scale.min_x) * x / WIDTH;
	data->fractal.c.c_im = data->scale.min_y + (data->scale.max_y - data->scale.min_y) * y / HEIGHT;
	draw_fractal(*data);
	put_image(data->mlx);
	return (1);
}

void	zoom_in(t_data *data)
{
	data->scale.max_x = data->scale.max_x * ZOOM_IN_STRENGTH;
	data->scale.min_x = data->scale.min_x * ZOOM_IN_STRENGTH;
	data->scale.max_y = data->scale.max_y * ZOOM_IN_STRENGTH;
	data->scale.min_y = data->scale.min_y * ZOOM_IN_STRENGTH;
	data->fractal.max_iter += 2;
}

void	zoom_out(t_data *data)
{
	data->scale.max_x = data->scale.max_x * ZOOM_OUT_STRENGTH;
	data->scale.min_x = data->scale.min_x * ZOOM_OUT_STRENGTH;
	data->scale.max_y = data->scale.max_y * ZOOM_OUT_STRENGTH;
	data->scale.min_y = data->scale.min_y * ZOOM_OUT_STRENGTH;
	if (data->fractal.max_iter > 2)
		data->fractal.max_iter -= 2;
}