/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:40:44 by falberti          #+#    #+#             */
/*   Updated: 2024/02/27 15:50:46 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(t_game *g, char **map_checkers, int row, int col )
{
	if (row < 1 || row > (g->max_y - 1)
		|| col < 1 || col > (g->max_x - 1))
		return ;
	if (map_checkers[row][col] == '1'
		|| g->map[row][col] == '1')
		return ;
	map_checkers[row][col] = '1';
	if (g->map[row][col] == 'C')
		g->eat_checker++;
	if (g->map[row][col] == 'E')
		g->exit_checker++;
	flood_fill(g, map_checkers, row + 1, col);
	flood_fill(g, map_checkers, row - 1, col);
	flood_fill(g, map_checkers, row, col + 1);
	flood_fill(g, map_checkers, row, col - 1);
}

int	is_map_valid(t_game *game)
{
	char	**map_checker;

	map_checker = readmap("../assets/maps/exemple_one.ber");
	flood_fill(game, map_checker, game->max_y, game->max_x);
	free_map(map_checker);
	if (game->eat_checker != game->nb_eatable || game->exit_checker != 1)
		return (0);
	return (1);
}