/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:23:20 by jbernard          #+#    #+#             */
/*   Updated: 2021/10/28 16:21:50 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_testing.h"

t_mlx	init_mlx()
{
	t_mlx mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Minilibx testing...");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	mlx.addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel, &mlx.size_line, &mlx.endian);

}

int	put_pixel(t_mlx mlx, int x, int y, unsigned int color)
{
	int pos;

	mlx.addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel, &mlx.size_line, &mlx.endian);
	pos = (y * mlx.size_line + x * (mlx.bits_per_pixel / 8));
	mlx.addr += pos;
	*(unsigned int *)mlx.addr = color;
	return (1);
}

