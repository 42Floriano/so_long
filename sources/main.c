/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:28:35 by falberti          #+#    #+#             */
/*   Updated: 2024/02/28 12:41:06 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	av_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i -= 1;
	if (str[i - 3] == '.' && str[i - 2] == 'b'
		&& str[i - 1] == 'e' && str[i] == 'r')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2 || av_checker(av[1]))
	{
		printff("Error\nInvalid Sytax");
		exit(1);
	}
	else
	{
		game.map = readmap(av[1]);
		if (map_checkers(&game, av[1]))
		{
			
		}
		else
		{
			if (game.map)
				free_map(game.map);
			printff("Error\nMap nValid");
			exit(1);
		}
	}
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
