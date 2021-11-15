/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:41:55 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/15 15:55:37 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_event_manager(int button, int x, int y, t_data *data)
{
	if (button == 4)
		zoom_out(data, x, y);
	if (button == 5)
		zoom_in(data, x, y);
	draw_fractal(*data);
	put_image(data->mlx);
	return (1);
}

int	key_event_manager(int key_code, t_data *data)
{
	printf("Keycode : %d\n", key_code);
	printf("Fractal : %d", data->fractal.max_iter);
	return (1);
}

int	mouse_motion_event()
{
	printf("OK");
	return (1);
}