/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:23:20 by jbernard          #+#    #+#             */
/*   Updated: 2021/12/09 11:38:53 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	init_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W, H, "Fractol");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, W, H);
	mlx.addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.sl, &mlx.edn);
	return (mlx);
}

int	put_fractal_pixels(t_mlx mlx, t_fractal f, int x, int y)
{	
	if (f.curr_iter != f.max_iter)
	{
		mlx.addr[(x * 4) + (y * W * 4)] = 0 + (f.curr_iter * 120) % 256;
		mlx.addr[(x * 4) + (y * W * 4) + 1] = 0 + (f.curr_iter * 60) % 256;
		mlx.addr[(x * 4) + (y * W * 4) + 2] = 0 + (f.curr_iter * 25) % 256;
	}
	else
	{
		mlx.addr[(x * 4) + (y * W * 4)] = 0;
		mlx.addr[(x * 4) + (y * W * 4) + 1] = 0;
		mlx.addr[(x * 4) + (y * W * 4) + 2] = 0;
	}
	return (1);
}

void	put_image(t_mlx mlx)
{
	mlx_put_image_to_window (mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
}
