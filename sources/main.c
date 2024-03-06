/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:28:35 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 10:09:40 by albertini        ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2 || av_checker(av[1]))
		printf("Error\nInvalid Sytax");
	else
	{
		init_struct(&game);
		game.map = readmap(av[1]);
		if (map_checkers(&game, av[1]))
		{
			init_game(&game);
			commands(&game);
			mlx_loop(game.mlx_ptr);
		}
		else
		{
			if (game.map)
				free_map(game.map);
			printf("Error\nMap nValid\n");
		}
	}
	exit (1);
	return (0);
}

