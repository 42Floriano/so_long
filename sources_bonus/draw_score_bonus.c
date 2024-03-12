/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_score_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:56:55 by falberti          #+#    #+#             */
/*   Updated: 2024/03/12 14:07:49 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	draw_score(t_game *g)
{
	char	*str;

	str = ft_itoa(g->player_moves);
	mlx_string_put(g->mlx_ptr, g->win_ptr, 25, 20, 0xFFFFFF, "Moves: ");
	mlx_string_put(g->mlx_ptr, g->win_ptr, 100, 20, 0xFFFFFF, str);
	free(str);
	return ;
}
