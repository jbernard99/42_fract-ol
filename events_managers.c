/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_managers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:48:55 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/22 13:47:38 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_event_manager(int button, int x, int y, t_data *data)
{
	if (button == 4)
		zoom_out(data, x, y);
	else if (button == 5)
		zoom_in(data, x, y);
	
	update_fractal(*data);
	return (1);
}

int	key_event_manager(int key_code, t_data *data)
{
	if (key_code >= 123 && key_code <= 126)
		move(data, key_code);
	else if (key_code == 53)
		quit(data);
		
	update_fractal(*data);
	return (1);
}