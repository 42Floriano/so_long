/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:28:35 by falberti          #+#    #+#             */
/*   Updated: 2024/02/20 16:05:24 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_var	vars;

	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (1);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 800, 800, "Hello world!");
	vars.img.img_ptr = mlx_new_image(vars.mlx_ptr, 800, 800);
	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr,
			&vars.img.bit_per_pixel,
			&vars.img.line_len,
			&vars.img.endian);
	if (vars.win_ptr == NULL)
	{
		mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
		free(vars.mlx_ptr);
		return (1);
	}
	commands(&vars);
	mlx_loop(vars.mlx_ptr);
	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
	free(vars.mlx_ptr);
}
