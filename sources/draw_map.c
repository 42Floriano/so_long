/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:36:29 by falberti          #+#    #+#             */
/*   Updated: 2024/03/05 16:16:00 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	draw_img(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
	(game->mlx_ptr, game->win_ptr, image, x * 32, y * 32);
}

static void	draw_bg(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			draw_img(g, g->img_bg, x, y);
			x++;
		}
		y++;
	}
	return ;
}

static void	draw_exit(t_game *g, int x, int y)
{
	if (g->exit_ok == 1)
	{
		mlx_destroy_image(g->mlx_ptr, g->img_exit);
		g->img_exit = mlx_xpm_file_to_image
			(g->mlx_ptr, "assets/onMap/EXIT.xpm", &g->img_w, &g->img_h);
	}
	draw_img(g, g->img_exit, x, y);
}

void	draw_map(t_game *g)
{
	int	x;
	int	y;

	draw_bg(g);
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '1')
				draw_img(g, g->img_wall, x, y);
			if (g->map[y][x] == 'P')
				draw_img(g, g->img_pu, x, y);
			if (g->map[y][x] == 'C')
				draw_img(g, g->img_c, x, y);
			if (g->map[y][x] == 'E')
				draw_exit(g, x, y);
			x++;
		}
		y++;
	}
	return ;
}
