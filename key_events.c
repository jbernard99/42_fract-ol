/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:59:01 by jbernard          #+#    #+#             */
/*   Updated: 2021/12/09 11:47:49 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_data *data, int key_code)
{
	if (data->f.max_iter <= 30)
	{
		if (key_code == 126)
		{
			data->s.min_y -= MOVEMENT;
			data->s.max_y -= MOVEMENT;
		}
		else if (key_code == 125)
		{
			data->s.min_y += MOVEMENT;
			data->s.max_y += MOVEMENT;
		}
		else if (key_code == 124)
		{
			data->s.min_x += MOVEMENT;
			data->s.max_x += MOVEMENT;
		}
		else if (key_code == 123)
		{
			data->s.min_x -= MOVEMENT;
			data->s.max_x -= MOVEMENT;
		}
	}
}

void	raise_max_iter(t_data *data)
{
	data->f.max_iter += 1;
}

void	lower_max_iter(t_data *data)
{
	if (data->f.max_iter > 2)
		data->f.max_iter -= 1;
}

void	reset_positions(t_data *data)
{
	data->s.min_x = -2;
	data->s.max_x = 2;
	data->s.min_y = -2;
	data->s.max_y = 2;
	data->f.max_iter = 10;
	update_fractal(data);
}

void	quit(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.img_ptr);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	exit(0);
}
