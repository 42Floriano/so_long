/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:21:33 by falberti          #+#    #+#             */
/*   Updated: 2024/03/12 13:15:13 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_struct(t_game *g)
{
	g->mlx_ptr = NULL;
	g->win_ptr = NULL;
	g->map = NULL;
	g->img_bg = NULL;
	g->img_wall = NULL;
	g->img_pu = NULL;
	g->img_pd = NULL;
	g->img_c = NULL;
	g->img_exit = NULL;
	g->map_w = 0;
	g->map_h = 0;
	g->img_w = 0;
	g->img_h = 0;
	g->player_x = 0;
	g->player_y = 0;
	g->player_score = 0;
	g->player_moves = 0;
	g->exit_portal = 0;
	g->entry_portal = 0;
	g->nb_eatable = 0;
	g->max_x = 0;
	g->max_y = 0;
	g->exit_checker = 0;
	g->eat_checker = 0;
	g->exit_ok = 0;
}
