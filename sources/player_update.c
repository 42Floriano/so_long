/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:26:24 by falberti          #+#    #+#             */
/*   Updated: 2024/02/23 15:39:24 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


static	int	move_is_possible(t_game *vars, int x, int y)
{
	if (vars->map[y][x] != '1')
		return (1);
	return (0);
}

int	playermove(int keycode, t_game *game)
{
	if (keycode == 1
		&& move_is_possible(game, game->player_x + 1, game->player_y))
	{
		game->player_x += 1;
		game->player_moves++;
	}
	else if (keycode == 2
		&& move_is_possible(game, game->player_x - 1, game->player_y))
	{
		game->player_x -= 1;
		game->player_moves++;
	}
	else if (keycode == 3
		&& move_is_possible(game, game->player_y - 1, game->player_y))
	{
		game->player_y -= 1;
		game->player_moves++;
	}
	else if (keycode == 4
		&& move_is_possible(game, game->player_y + 1, game->player_y))
	{
		game->player_y += 1;
		game->player_moves++;
	}
	return (0);
}