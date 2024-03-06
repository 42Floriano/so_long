/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:40:43 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 10:55:10 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	press_direction(int keycode, t_game *game)
{
	if (keycode == KEYCODE_RIGHT_ARROW || keycode == KEYCODE_D)
		playermove(1, game);
	else if (keycode == KEYCODE_LEFT_ARROW || keycode == KEYCODE_A)
		playermove(2, game);
	else if (keycode == KEYCODE_UP_ARROW || keycode == KEYCODE_W)
		playermove(3, game);
	else if (keycode == KEYCODE_DOWN_ARROW || keycode == KEYCODE_S)
		playermove(4, game);
	return (0);
}

static int	quitgame(int keycode, t_game *game)
{
	if (keycode == KEYCODE_ESC)
	{
		ft_printf("The %d key (ESC) has been pressed\n", keycode);
		exit_game(game);
	}
	return (1);
}

static int	close_cross(t_game *game)
{
	exit_game(game);
	return (1);
}

void	commands(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 0, press_direction, game);
	mlx_hook(game->win_ptr, 17, 0, close_cross, game);
	mlx_hook(game->win_ptr, 3, 0, quitgame, game);
}
