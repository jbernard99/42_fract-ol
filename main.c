/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:30:50 by jbernard          #+#    #+#             */
/*   Updated: 2021/12/08 23:30:47 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

t_data	init_data(void)
{
	t_data	data;

	data.mlx = init_mlx();
	data.scale = init_scale();
	data.fractal = init_fractal(MAX_ITER);
	data.type = 0;
	return (data);
}

void	update_fractal(t_data *data)
{
	draw_fractal(data);
	put_image(data->mlx);
}

void	print_menu(t_data data)
{
	printf("Welcome to my Fractal\n\n");
	printf("How to use:	  ./fractol.out [Fractal Name]\n\n");
	printf("Available fractals:\n\n");
	printf("	- Mandelbrot\n        - Julia\n        - BurningShip\n");
	printf("\n\nHave fun! :)\n");
	if (data.type != -1)
		quit(&data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.type = -1;
	if (argc == 2)
	{
		data = init_data();
		mlx_mouse_hook(data.mlx.win_ptr, mouse_event_manager, &data);
		mlx_key_hook(data.mlx.win_ptr, key_event_manager, &data);
		if (ft_strncmp("mandlebrot", argv[1], 4) == 0)
			data.type = 0;
		else if (ft_strncmp("julia", argv[1], 4) == 0)
		{
			data.type = 1;
			mlx_hook(data.mlx.win_ptr, 6, 3, move_cursor, &data);
		}
		else if (ft_strncmp("burning", argv[1], 4) == 0)
			data.type = 2;
		else
			print_menu(data);
		update_fractal(&data);
		mlx_loop(data.mlx.mlx_ptr);
	}
	else
		print_menu(data);
	return (0);
}
