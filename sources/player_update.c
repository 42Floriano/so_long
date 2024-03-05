/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:26:24 by falberti          #+#    #+#             */
/*   Updated: 2024/03/05 16:55:55 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		game->player_moves++;
		printf("Nb moves: %d\n", game->player_moves);
		return (1);	
	}
	return (0);
}

static	void	check_score(t_game *g)
{
	if (g->player_score == g->nb_eatable)
		g->exit_ok = 1;
	return ;
}

// static	void	print_map(t_game *g)
// {
// 	int	i;

// 	i = 0;
// 	printf("Map\n");
// 	while (g->map[i])
// 		printf("%s\n", g->map[i++]);
// 	return ;
// }

int	playermove(int k, t_game *g)
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
	draw_map(g);
	//print_map(g);
	check_score(g);
	return (0);
}
