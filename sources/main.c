/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:28:35 by falberti          #+#    #+#             */
/*   Updated: 2024/02/29 22:07:02 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	av_checker(char *str)
{
	int	i;

	i = (ft_strlen(str) - 1);
	if (str[i - 3] == '.' && str[i - 2] == 'b'
		&& str[i - 1] == 'e' && str[i] == 'r')
		return (0);
	return (1);
}

static void	print_struct_game(t_game *game)
{
	printf("Player X: %d\n", game->player_x);
	printf("Player Y: %d\n", game->player_y);
	printf("Player Score: %d\n", game->player_score);
	printf("Player Moves: %d\n", game->player_moves);
	printf("Exit Portal: %d\n", game->exit_portal);
	printf("Entry Portal: %d\n", game->entry_portal);
	printf("Nb Eatable: %d\n", game->nb_eatable);
	printf("Max Y: %d\n", game->max_y);
	printf("Max X: %d\n", game->max_x);
	printf("Y: %d\n", game->y);
	printf("X: %d\n", game->x);
	printf("Exit Checker: %d\n", game->exit_checker);
	printf("Eat Checker: %d\n", game->eat_checker);
	printf("Exit Ok: %d\n", game->exit_ok);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2 || av_checker(av[1]))
	{
		printf("Error\nInvalid Sytax");
		exit(1);
	}
	else
	{
		init_struct(&game);
		print_struct_game(&game);
		game.map = readmap(av[1]);
		if (map_checkers(&game, av[1]))
		{
			//print_struct_game(&game);
			init_game(&game);
			commands(&game);
			mlx_loop(game.mlx_ptr);
			mlx_destroy_window(game.mlx_ptr, game.win_ptr);
			free(game.mlx_ptr);
		}
		else
		{
			if (game.map)
				free_map(game.map);
			printf("Error\nMap nValid");
			exit(1);
		}
	}
	return (0);
}
