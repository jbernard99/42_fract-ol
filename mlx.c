/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:30:50 by jbernard          #+#    #+#             */
/*   Updated: 2021/10/21 15:50:13 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -Wall -Werror -Wextra -Imlx -lmlx -framework OpenGL -framework AppKit mlx.c
//#include "mlx_testing.h"
#include <mlx.h>

typedef struct window {
	void			*win_ptr;
	void			*mlx_ptr;
	unsigned int 	width;
	unsigned int 	height;
} window;

window	init_window(unsigned int width, unsigned int height)
{
	window win;

	win.mlx_ptr = mlx_init();
	win.width = width;
	win.height = height;
	win.win_ptr = mlx_new_window(win.mlx_ptr, win.width, win.height, "MiniLibX testing...");

	return (win);
}

int	put_pixel(window win, unsigned int x, unsigned int y, unsigned int color)
{
	if (x < 0 || x > win.width)
		return (0);
	else if (y < 0 || y > win.height)
		return (0);
	mlx_pixel_put(win.mlx_ptr, win.win_ptr, x, y, color);
	return (1);
}

int	draw_horizontal_line(window win, unsigned int start_x, unsigned int end_x, unsigned int y)
{
	while (start_x != end_x)
	{
		if (!put_pixel(win, start_x, y, 0xFFFFFF))
			return (0);
		if (start_x < end_x)
			start_x++;
		else
			start_x--;
	}
	return (1);
}

int	draw_vertical_line(window win, unsigned int start_y, unsigned int end_y, unsigned int x)
{
	while (start_y != end_y)
	{
		if (!put_pixel(win, x, start_y, 0xFFFFFF))
			return (0);
		if (start_y < end_y)
			start_y++;
		else
			start_y--;
	}
	return (1);
}

void	draw_box(window win, unsigned int starting_x, unsigned int starting_y, unsigned int segment_len)
{
	draw_horizontal_line(win, starting_x, starting_x + segment_len, starting_y);
	draw_horizontal_line(win, starting_x, starting_x + segment_len, starting_y + segment_len);
	draw_vertical_line(win, starting_y, starting_y + segment_len, starting_x);
	draw_vertical_line(win, starting_y, starting_y + segment_len, starting_x + segment_len);
}

int	main()
{
	window win;
	
	win = init_window(1280, 720);
	draw_box(win, 50, 50, 750);
	mlx_loop(win.mlx_ptr);
	return (0);
}