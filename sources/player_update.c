/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:26:24 by falberti          #+#    #+#             */
/*   Updated: 2024/02/22 17:06:58 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


static	int	move_is_possible(t_var *vars, int x, int y)
{
	if (vars->map[y][x] != '1')
		return (1);
	return (0);
}

static int	playermove(int keycode, t_var *vars)
{
	if (keycode == 1 &&
		move_is_possible(vars, vars->player.pos.x + 1, vars->player.pos.y))
	{
		vars->player.pos.x += 1;
		nb_move++;
	}
	else if (keycode == 2 &&
		move_is_possible(vars, vars->player.pos.x - 1, vars->player.pos.y))
	{
		vars->player.pos.x -= 1;
		nb_move++;
	}
	else if (keycode == 3 &&
		move_is_possible(vars, vars->player.pos.y - 1, vars->player.pos.y))
	{
		vars->player.pos.y -= 1;
		nb_move++;
	}
	else if (keycode == 4 &&
		move_is_possible(vars, vars->player.pos.y + 1, vars->player.pos.y))
	{
		vars->player.pos.y += 1;
		nb_move++;
	}
	return (0);
}