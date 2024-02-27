/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:15 by falberti          #+#    #+#             */
/*   Updated: 2024/02/27 12:44:01 by falberti         ###   ########.fr       */
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
		if (ft_strlen(map[y]) == ft_strlen(map[0]))
			return (0);
	return (1 * ok);
}

static int	closed_by_walls(char **map)
{
	int	y;
	int	x;
	int	len_x;

	y = 0;
	x = 0;
	len_x = ft_strlen(map[0]);
	while (map[y])
		y++;
	while (map[0][x])
		if (map[0][x] != '1' && map[y - 1][x] != '1')
			return (0);
		x++;
	y = 0;
	while (map[y])
		if (map[y][0] != '1' || map[y][len_x] != '1')
			return (0);
		y++;
	return (1);
}

static int	is_there_epc(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				game->exit_portal++;
			if (game->map[y][x] == 'P')
				game->entry_portal++;
			if (game->map[y][x] == 'C')
				game->nb_eatable++;
			x++;
		}
		y++;
	}
	if (game->exit_portal != 1
		|| game->entry_portal != 1
		|| game->nb_eatable <= 0)
		return (0);
	return (1);
}

// must be changed with game instead
int	map_checkers(t_game *game)
{
	if (!is_rectangle_and_nempty(game->map)
		|| !closed_by_walls(game->map)
		|| !is_there_epc(game))
		return (0);
	return (1);
}