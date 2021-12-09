/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:03:00 by jbernard          #+#    #+#             */
/*   Updated: 2021/12/09 11:39:04 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	move_cursor(int x, int y, t_data *data)
{
	data->f.c.c_real = data->s.min_x + (data->s.max_x - data->s.min_x) * x / W;
	data->f.c.c_im = data->s.min_y + (data->s.max_y - data->s.min_y) * y / H;
	draw_fractal(data);
	put_image(data->mlx);
	return (1);
}

void	zoom_in(t_data *data)
{
	data->s.max_x = data->s.max_x * ZOOM_IN_STRENGTH;
	data->s.min_x = data->s.min_x * ZOOM_IN_STRENGTH;
	data->s.max_y = data->s.max_y * ZOOM_IN_STRENGTH;
	data->s.min_y = data->s.min_y * ZOOM_IN_STRENGTH;
	data->f.max_iter += 2;
}

void	zoom_out(t_data *data)
{
	if (data->f.max_iter > 2)
	{
		data->f.max_iter -= 2;
		data->s.max_x = data->s.max_x * ZOOM_OUT_STRENGTH;
		data->s.min_x = data->s.min_x * ZOOM_OUT_STRENGTH;
		data->s.max_y = data->s.max_y * ZOOM_OUT_STRENGTH;
		data->s.min_y = data->s.min_y * ZOOM_OUT_STRENGTH;
	}
}
