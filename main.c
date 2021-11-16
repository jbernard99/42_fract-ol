/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:30:50 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/15 22:33:37 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -Wall -Werror -Wextra -Imlx -lmlx -framework OpenGL -framework AppKit mlx.c
#include "fractal.h"

t_data	init_data()
{
	t_data data;

	data.mlx = init_mlx();
	data.scale = init_scale();
	data.fractal = init_fractal(MAX_ITER);

	return (data);
}

int	main(void)
{
	t_data data;

	data = init_data();

	draw_fractal(data);
	put_image(data.mlx);
	
	mlx_mouse_hook(data.mlx.win_ptr, mouse_event_manager, &data);
	mlx_key_hook(data.mlx.win_ptr, key_event_manager, &data);
	//mlx_hook(data.mlx.win_ptr, 6, 1L<<6, mouse_motion_event, &data);

	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
