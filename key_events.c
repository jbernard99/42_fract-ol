/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:59:01 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/15 22:38:22 by jbernard         ###   ########.fr       */
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

int	key_event_manager(int key_code, t_data *data)
{
	printf("Keycode : %d\n", key_code);
	printf("Fractal : %d", data->fractal.max_iter);

	if (key_code >= 123 && key_code <= 126)
		move(data, key_code);
		
	draw_fractal(*data);
	put_image(data->mlx);
	return (1);
}