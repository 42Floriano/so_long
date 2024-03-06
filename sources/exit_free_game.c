/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:47:15 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 10:08:03 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx_ptr, game->img_bg);
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_image(game->mlx_ptr, game->img_pu);
	mlx_destroy_image(game->mlx_ptr, game->img_pd);
	mlx_destroy_image(game->mlx_ptr, game->img_c);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	//mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit (0);
}
