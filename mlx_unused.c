/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_unused.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:25:25 by jbernard          #+#    #+#             */
/*   Updated: 2021/10/28 15:50:12 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_testing.h"

int	put_pixel_window(t_mlx mlx, unsigned int x, unsigned int y, unsigned int color)
{
	if (x < 0 || x > WIDTH)
		return (0);
	else if (y < 0 || y > WIDTH)
		return (0);
	mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x, y, color);
	return (1);
}

void	paint_image(t_mlx mlx, unsigned int color)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(mlx, x, y, color);
			x++;
		}
		y++;
	}
}