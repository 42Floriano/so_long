/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:58:29 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 10:37:36 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	img_init(t_game *g)
{
	g->img_bg = mlx_xpm_file_to_image
		(g->mlx_ptr, "assets/onMap/bg3.xpm", &g->img_w, &g->img_h);
	g->img_wall = mlx_xpm_file_to_image
		(g->mlx_ptr, "assets/onMap/1-2.xpm", &g->img_w, &g->img_h);
	g->img_pu = mlx_xpm_file_to_image
		(g->mlx_ptr, "assets/onMap/PU.xpm", &g->img_w, &g->img_h);
	g->img_pd = mlx_xpm_file_to_image
		(g->mlx_ptr, "assets/onMap/PD.xpm", &g->img_w, &g->img_h);
	g->img_c = mlx_xpm_file_to_image
		(g->mlx_ptr, "assets/onMap/C.xpm", &g->img_w, &g->img_h);
	g->img_exit = mlx_xpm_file_to_image
		(g->mlx_ptr, "assets/onMap/EXITG.xpm", &g->img_w, &g->img_h);
	return ;
}

static	void	size_window(t_game *game)
{
	game->map_w = (game->max_x * 32);
	game->map_h = (game->max_y * 32);
}

int	init_game(t_game *g)
{
	g->mlx_ptr = mlx_init();
	if (g->mlx_ptr == NULL)
		return (0);
	size_window(g);
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->map_w, g->map_h, "So_long");
	if (g->win_ptr == NULL)
	{
		mlx_destroy_window(g->mlx_ptr, g->win_ptr);
		free(g->mlx_ptr);
		return (0);
	}
	img_init(g);
	draw_map(g);
	return (1);
}

