/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:03:00 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/17 13:40:29 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

// void	set_starting_z(t_data *data, int x, int y)
// {
// 	data->fractal.complex.z_real = (double)x / WIDTH * 0.75;
// 	data->fractal.complex.z_imaginary = (double)y / HEIGHT * 0.54;
// 	printf("New Z set : \n    Real : %Lf\n    Imaginary : %Lf\n", data->fractal.complex.z_real, data->fractal.complex.z_imaginary);
// 	printf("C : \n    Real : %Lf\n    Imaginary : %Lf\n\n", data->fractal.complex.c_real, data->fractal.complex.c_imaginary);
// }

int	mouse_event_manager(int button, int x, int y, t_data *data)
{
	// if (button == 1)
	// 	set_starting_z(data, x, y);
	if (button == 4)
		zoom_out(data, x, y);
	else if (button == 5)
		zoom_in(data, x, y);
	
	draw_fractal(*data);
	put_image(data->mlx);
	return (1);
}