/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_testing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:02:09 by jbernard          #+#    #+#             */
/*   Updated: 2021/10/21 14:33:39 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

#include <stdio.h>
#include <mlx.h>

typedef struct window {
	void			*win_ptr;
	void			*mlx_ptr;
	unsigned int 	width;
	unsigned int 	height;
} window;

#endif