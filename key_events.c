/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:59:01 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/23 14:31:51 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	move(t_data *data, int key_code)
{
	if (key_code == 126)
	{
		data->scale.min_y -= 0.01;
		data->scale.max_y -= 0.01;
	}
	else if (key_code == 125)
	{
		data->scale.min_y += 0.01;
		data->scale.max_y += 0.01;
	}
	else if (key_code == 124)
	{
		data->scale.min_x += 0.01;
		data->scale.max_x += 0.01;
	}
	else if (key_code == 123)
	{
		data->scale.min_x -= 0.01;
		data->scale.max_x -= 0.01;
	}
}

void	quit(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.img_ptr);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	exit(0);
}