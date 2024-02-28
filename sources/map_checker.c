/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:15 by falberti          #+#    #+#             */
/*   Updated: 2024/02/28 12:29:57 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_rectangle_and_nempty(char **map)
{
	int	y;
	int	x;
	int	ok;

	y = 0;
	x = 0;
	ok = 0;
	while (map[y])
		while (map[y][x])
			if (map[y][x] != '0' && map[y][x] != '1')
				ok = 1;
			x++;
		y++;
	if (y >= x)
		return (0);
	y = 0;
	x = 0;
	while (map[y++])
		if (ft_strlen(map[y]) != ft_strlen(map[0]))
			return (0);
	return (1 * ok);
}

static int	closed_by_walls(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	while (game->map[0][x])
		if (game->map[0][x] != '1' && game->map[game->max_x][x] != '1')
			return (0);
		x++;
	y = 0;
	while (game->map[y])
		if (game->map[y][0] != '1' || game->map[y][game->max_x] != '1')
			return (0);
		y++;
	return (1);
}

static int	is_there_epc(t_game *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == 'E')
				game->exit_portal++;
			if (game->map[game->y][game->x] == 'P')
			{
				game->entry_portal++;
				game->player_x = game->x;
				game->player_y = game->y;
			}
			if (game->map[game->y][game->x] == 'C')
				game->nb_eatable++;
			game->x++;
		}
		game->y++;
	}
	if (game->exit_portal != 1 || game->entry_portal != 1
		|| game->nb_eatable <= 0)
		return (0);
	return (1);
}

// must be changed with game instead
int	map_checkers(t_game *game, char *path)
{
	int	y;

	y = 0;
	while (game->map[y])
		y++;
	game->max_y = y;
	game->max_x = ft_strlen(game->map[0]);
	if (!is_rectangle_and_nempty(game->map)
		|| !closed_by_walls(game)
		|| !is_there_epc(game))
		return (0);
	if (!is_map_valid(game, path))
		return (0);
	return (1);
}