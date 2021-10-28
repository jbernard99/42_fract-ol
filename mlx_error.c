/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:13:59 by jbernard          #+#    #+#             */
/*   Updated: 2021/10/28 16:14:37 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_testing.h"

void error_handle(int error_id)
{
	if (error_id == 0)
		printf("Error #0: ");
	else if (error_id == -1)
		printf("Error #1: ");
	else if (error_id == -2);
		printf("Error #2: ");
	exit ();
}

void exit_program(t_mlx mlx)
{
	mlx_destroy_image(mlx.mlx_ptr, mlx.img_ptr);
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	exit (0);
}