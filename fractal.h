/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:02:09 by jbernard          #+#    #+#             */
/*   Updated: 2021/11/15 16:30:59 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TESTING_H
#define MLX_TESTING_H


# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITER 3

#include <mlx.h>
#include <stdio.h>

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_mlx;

typedef struct s_scale {
	long double min_x;
	long double max_x;
	long double min_y;
	long double max_y;
}	t_scale;

typedef struct s_complex {
	long double z_real;
	long double z_imaginary;
	long double c_real;
	long double c_imaginary;
}	t_complex;

typedef struct s_fractal {
	t_complex complex;
	unsigned int curr_iter;
	unsigned int max_iter;
}	t_fractal;

typedef struct s_data {
	t_mlx mlx;
	t_scale scale;
	t_fractal fractal;
}	t_data;

// mlx_tools.c //
t_mlx	init_mlx();
int	put_fractal_pixels(t_mlx mlx, t_fractal fractal, unsigned int x, unsigned int y);
void	put_image(t_mlx mlx);
void	zoom_in(t_data *data, int x, int y);
void	zoom_out(t_data *data, int x, int y);

// event_handler.c //
int	mouse_event_manager(int button, int x, int y, t_data *data);
int	key_event_manager(int key_code, t_data *data);
void	move(t_data *data, int key_code);

// mlx_unused.c //
int		put_pixel_window(t_mlx mlx, unsigned int x, unsigned int y, unsigned int color);
void	paint_image(t_mlx mlx, unsigned int color);

// fractal.c //
t_fractal init_fractal();
t_scale	init_scale();
t_complex	init_complex();
int	draw_fractal(t_data data);

// mandelbrot.c //
unsigned int	mandelbrot(t_fractal f, t_scale s, unsigned int x, unsigned int y);

#endif