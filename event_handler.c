/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:41:55 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/12 11:35:52 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_testing.h"

int	mouse_event_manager(int button, int x, int y, t_data *data)
{
	if (button == 5)
		zoom_out(data);
	if (button == 4)
		zoom_in(data, x, y);

	return (1);
}

int	key_event_manager(int key_code, t_data *data)
{
	printf("Keycode : %d\n", key_code);
	printf("Fractal : %d", data->fractal.max_iter);
	return (1);
}
