/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:26:24 by falberti          #+#    #+#             */
/*   Updated: 2024/03/12 15:20:28 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static	int	move_is_possible(t_game *game, int x, int y)
{
	if (game->exit_ok == 0 && game->map[y][x] == 'E')
		return (0);
	if (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
		{
			game->player_score += 1;
			game->map[y][x] = '0';
		}
		if (game->map[y][x] == 'E' && game->exit_ok == 1)
			exit_game(game);
		if (game->map[y][x] == 'K')
		{
			ft_printf("GAME OVER !!\n ... noob");
			exit_game(game);
		}	
		game->player_moves++;
		return (1);
	}
	return (0);
}

static	void	check_score(t_game *g)
{
	if (g->player_score == g->nb_eatable)
		g->exit_ok = 1;
	draw_map(g);
	return ;
}

void	playermove(int k, t_game *g)
{
	if (k == 1 && move_is_possible(g, g->player_x + 1, g->player_y))
	{
		g->player_x += 1;
		g->map[g->player_y][g->player_x] = 'P';
		g->map[g->player_y][g->player_x - 1] = '0';
	}
	else if (k == 2 && move_is_possible(g, g->player_x - 1, g->player_y))
	{
		g->player_x -= 1;
		g->map[g->player_y][g->player_x] = 'P';
		g->map[g->player_y][g->player_x + 1] = '0';
	}
	else if (k == 3 && move_is_possible(g, g->player_x, g->player_y - 1))
	{
		g->player_y -= 1;
		g->map[g->player_y][g->player_x] = 'P';
		g->map[g->player_y + 1][g->player_x] = '0';
	}
	else if (k == 4 && move_is_possible(g, g->player_x, g->player_y + 1))
	{
		g->player_y += 1;
		g->map[g->player_y][g->player_x] = 'P';
		g->map[g->player_y - 1][g->player_x] = '0';
	}
	check_score(g);
}
