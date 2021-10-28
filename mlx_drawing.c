/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:16:14 by jbernard          #+#    #+#             */
/*   Updated: 2021/10/28 15:47:03 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_testing.h"

int	draw_horizontal_line(t_mlx mlx, unsigned int start_x, unsigned int end_x, unsigned int y)
{
	while (start_x != end_x)
	{
		if (!put_pixel(mlx, start_x, y, 0xFFFFFF))
			return (0);
		if (start_x < end_x)
			start_x++;
		else
			start_x--;
	}
	return (1);
}

int	draw_vertical_line(t_mlx mlx, unsigned int start_y, unsigned int end_y, unsigned int x)
{
	while (start_y != end_y)
	{
		if (!put_pixel(mlx, x, start_y, 0xFFFFFF))
			return (0);
		if (start_y < end_y)
			start_y++;
		else
			start_y--;
	}
	return (1);
} 

void	draw_box(t_mlx mlx, unsigned int starting_x, unsigned int starting_y, unsigned int segment_len)
{
	draw_horizontal_line(mlx, starting_x, starting_x + segment_len, starting_y);
	draw_horizontal_line(mlx, starting_x, starting_x + segment_len, starting_y + segment_len);
	draw_vertical_line(mlx, starting_y, starting_y + segment_len, starting_x);
	draw_vertical_line(mlx, starting_y, starting_y + segment_len, starting_x + segment_len);
}