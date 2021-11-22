/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:30:50 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/22 15:29:06 by jbernard         ###   ########.fr       */
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
	data.type = 0;

	return (data);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (*str1 && *str2 && --n)
	{
		if (*str1 != *str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

void	update_fractal(t_data data)
{
	draw_fractal(data);
	put_image(data.mlx);
}

int	main(int argc, char *argv[])
{
	t_data data;

	if (argc == 2)
	{
		data = init_data();
		mlx_mouse_hook(data.mlx.win_ptr, mouse_event_manager, &data);
		mlx_key_hook(data.mlx.win_ptr, key_event_manager, &data);
		if (ft_strncmp("julia", argv[1], 5) == 0 || ft_strncmp("Julia", argv[1], 5) == 0 )
		{
			data.type = 1;
			mlx_hook(data.mlx.win_ptr, 6, 3, move_cursor, &data);
		}
		else if (ft_strncmp("burning", argv[1], 4) == 0 || ft_strncmp("Burning", argv[1], 4) == 0)
			data.type = 2;
		draw_fractal(data);
		put_image(data.mlx);
		mlx_loop(data.mlx.mlx_ptr);
	}
	else
		return (0);
}
