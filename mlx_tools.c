/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:23:20 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/15 22:38:42 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_mlx	init_mlx()
{
	t_mlx mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Minilibx testing...");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	mlx.addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel, &mlx.size_line, &mlx.endian);
	printf("BBP : %d, SIZE_LINE : %d", mlx.bits_per_pixel, mlx.size_line);

	return (mlx);
}

int	put_fractal_pixels(t_mlx mlx, t_fractal fractal, unsigned int x, unsigned int y)
{	
	unsigned int color;

	color = 0x000000;
	if (fractal.curr_iter != fractal.max_iter)
	{
		mlx.addr[(x * 4) + (y * WIDTH * 4)] = color + (fractal.curr_iter * 2) % 256;
		mlx.addr[(x * 4) + (y * WIDTH * 4) + 1] = color + 0x0000FF + (fractal.curr_iter * 30) % 256;
		mlx.addr[(x * 4) + (y * WIDTH * 4) + 2] = color + 0x00FF00 + (fractal.curr_iter * 57) % 256;
	}
	else
	{
		mlx.addr[(x * 4) + (y * WIDTH * 4)] = 0;
		mlx.addr[(x * 4) + (y * WIDTH * 4) + 1] = 0;
		mlx.addr[(x * 4) + (y * WIDTH * 4) + 2] = 0;
	}
	return (1);
}

void	put_image(t_mlx mlx)
{
	mlx_put_image_to_window (mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
}