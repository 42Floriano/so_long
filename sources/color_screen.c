/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:04:46 by falberti          #+#    #+#             */
/*   Updated: 2024/02/22 16:41:59 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bit_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void	color_screen(t_var *data, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < 800)
	{
	y = 0;
		while (y < 800)
		{
			my_mlx_pixel_put(&data->img, x, y, color);
			y++;
		}
		x++;
	}
}

