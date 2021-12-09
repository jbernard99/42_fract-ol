/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:23:20 by jbernard          #+#    #+#             */
/*   Updated: 2021/12/08 23:31:10 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	init_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Minilibx testing...");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	mlx.addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel, &mlx.size_line, &mlx.endian);
	return (mlx);
}

int	put_fractal_pixels(t_mlx mlx, t_fractal fractal, unsigned int x, unsigned int y)
{	
	if (fractal.curr_iter != fractal.max_iter)
	{
		mlx.addr[(x * 4) + (y * WIDTH * 4)] = fractal.colors.R + (fractal.curr_iter * 120) % 256;
		mlx.addr[(x * 4) + (y * WIDTH * 4) + 1] = fractal.colors.G + (fractal.curr_iter * 60) % 256;
		mlx.addr[(x * 4) + (y * WIDTH * 4) + 2] = fractal.colors.B + (fractal.curr_iter * 25) % 256;
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

long double	get_scaled_center(t_scale s, int x, int y)
{
	long double	scaled_x;
	long double	scaled_y;

	scaled_x = s.min_x + (s.max_x - s.min_x) * x / WIDTH;
	scaled_y = s.min_y + (s.max_y - s.min_y) * y / HEIGHT;
	return (0.345);
}
