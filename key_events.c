/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:59:01 by jbernard          #+#    #+#             */
/*   Updated: 2021/12/08 23:12:31 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_data *data, int key_code)
{
	if (data->fractal.max_iter <= 10)
	{
		if (key_code == 126)
		{
			data->scale.min_y -= MOVEMENT;
			data->scale.max_y -= MOVEMENT;
		}
		else if (key_code == 125)
		{
			data->scale.min_y += MOVEMENT;
			data->scale.max_y += MOVEMENT;
		}
		else if (key_code == 124)
		{
			data->scale.min_x += MOVEMENT;
			data->scale.max_x += MOVEMENT;
		}
		else if (key_code == 123)
		{
			data->scale.min_x -= MOVEMENT;
			data->scale.max_x -= MOVEMENT;
		}
	}
}

void	raise_max_iter(t_data *data)
{
	data->fractal.max_iter += 1;
}

void	lower_max_iter(t_data *data)
{
	if (data->fractal.max_iter > 2)
		data->fractal.max_iter -= 1;
}

void	reset_positions(t_data *data)
{
	data->scale.min_x = -2;
	data->scale.max_x = 2;
	data->scale.min_y = -2;
	data->scale.max_y = 2;
	data->fractal.max_iter = 10;
	update_fractal(data);
}

void	quit(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.img_ptr);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	exit(0);
}
