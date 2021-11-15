/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:23:20 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/15 16:27:12 by jbernard         ###   ########.fr       */
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

void	zoom_in(t_data *data, int x, int y)
{
	long double mousex;
	long double mousey;

	mousex = x * (data->scale.max_x - data->scale.min_x) / WIDTH + data->scale.min_x;
	mousey = y * (data->scale.max_y - data->scale.min_y) / HEIGHT + data->scale.min_y;
	data->scale.max_x = data->scale.max_x / 1.1 + mousex * 0.1;
	data->scale.min_x = data->scale.min_x / 1.1 + mousex * 0.1;
	data->scale.max_y = data->scale.max_y / 1.1 + mousey * 0.1;
	data->scale.min_y = data->scale.min_y / 1.1 + mousey * 0.1;
	data->fractal.max_iter += 1;
	//printf("mousex = %Lf\nmousey = %Lf\nmin_x,y = %Lf,%Lf\nmax_x,y = %Lf,%Lf\n x,y = %d,%d\n\n\n", mousex, mousey, data->scale.min_x, data->scale.min_y, data->scale.max_x, data->scale.max_y, x, y);
	draw_fractal(*data);
	put_image(data->mlx);
}

void	zoom_out(t_data *data, int x, int y)
{
	long double mousex;
	long double mousey;

	mousex = x * (data->scale.max_x - data->scale.min_x) / WIDTH + data->scale.min_x;
	mousey = y * (data->scale.max_y - data->scale.min_y) / HEIGHT + data->scale.min_y;
	if (data->scale.max_x <= 2)
		data->scale.max_x = data->scale.max_x * 1.1 - mousex * 0.1;
	if (data->scale.min_x >= -2)
		data->scale.min_x = data->scale.min_x * 1.1 - mousex * 0.1;
	if (data->scale.max_y <= 2)
		data->scale.max_y = data->scale.max_y * 1.1 - mousey * 0.1;
	if (data->scale.max_y <= 2)
		data->scale.min_y = data->scale.min_y * 1.1 - mousex * 0.1;

	if (data->fractal.max_iter >= 3)
		data->fractal.max_iter -= 1;

	draw_fractal(*data);
	put_image(data->mlx);
}
