/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:30:50 by jbernard          #+#    #+#             */
/*   Updated: 2021/10/21 13:58:48 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1280, 720, "MiniLibX testing...");
	mlx_loop(mlx_ptr);
	return (0);
}