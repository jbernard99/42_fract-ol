/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_testing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:02:09 by jbernard          #+#    #+#             */
/*   Updated: 2021/10/28 16:19:38 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TESTING_H
#define MLX_TESTING_H


# define WIDTH 1280
# define HEIGHT 720

#include <mlx.h>
#include <stdio.h>

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_mlx;

typedef struct s_map {
	int	minX;
	int	maxX;
	int	minY;
	int	maxY;
}	t_map;

// mlx_tools.c //
t_mlx	init_mlx();
int		put_pixel(t_mlx mlx, int x, int y, unsigned int color);

// mlx_error.c //
void error_handle(int error_id);
void exit_program(t_mlx mlx);

// mlx_unsuned.c //
int		put_pixel_window(t_mlx mlx, unsigned int x, unsigned int y, unsigned int color);
void	paint_image(t_mlx mlx, unsigned int color);

#endif