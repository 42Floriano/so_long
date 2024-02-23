/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:28:35 by falberti          #+#    #+#             */
/*   Updated: 2024/02/23 15:56:56 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int	main(void)
{
	t_game	game;

	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return (1);
	game.win_ptr = mlx_new_window(game.mlx_ptr, 800, 800, "Hello world!");
	game.img.img_ptr = mlx_new_image(game.mlx_ptr, 800, 800);
	game.img.img_pixels_ptr = mlx_get_data_addr(game.img.img_ptr,
			&game.img.bit_per_pixel,
			&game.img.line_len,
			&game.img.endian);
	if (game.win_ptr == NULL)
	{
		mlx_destroy_window(game.mlx_ptr, game.win_ptr);
		free(game.mlx_ptr);
		return (1);
	}
	commands(&game);
	mlx_loop(game.mlx_ptr);
	mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	free(game.mlx_ptr);
}
