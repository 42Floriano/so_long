/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:26:24 by falberti          #+#    #+#             */
/*   Updated: 2024/02/20 16:47:40 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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