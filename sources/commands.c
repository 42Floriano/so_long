/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:40:43 by falberti          #+#    #+#             */
/*   Updated: 2024/02/20 16:50:52 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }

// static int	change_bg(int keycode, t_var *data)
// {
// 	if (keycode == KEYCODE_ESC)
// 	{
// 		printf("The %d key (ESC) has been pressed\n", keycode);
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		free(data->mlx_ptr);
// 		exit (1);
// 	}
// 	if (keycode == KEYCODE_R)
// 		color_screen(data, encode_rgb(255, 0, 0));
// 	else if (keycode == KEYCODE_G)
// 		color_screen(data, encode_rgb(0, 255, 0));
// 	else if (keycode == KEYCODE_B)
// 		color_screen(data, encode_rgb(0, 0, 255));
// 	mlx_put_image_to_window(data->mlx_ptr,
// 		data->win_ptr,
// 		data->img.img_ptr, 0, 0);
// 	return (0);
// }

static int	playermove(int keycode, t_var *vars)
{
	if (keycode == KEYCODE_RIGHT_ARROW || keycode == KEYCODE_D)
		playermove(1, vars);
	else if (keycode == KEYCODE_LEFT_ARROW || keycode == KEYCODE_A)
		playermove(2, vars);
	else if (keycode == KEYCODE_UP_ARROW || keycode == KEYCODE_W)
		playermove(3, vars);
	else if (keycode == KEYCODE_DOWN_ARROW || keycode == KEYCODE_S)
		playermove(4, vars);
	return (0);
}

static int	quitgame(int keycode, t_var *vars)
{
	if (keycode == KEYCODE_ESC)
	{
		printf("The %d key (ESC) has been pressed\n", keycode);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		free(vars->mlx_ptr);
		exit (1);
	}
	return (1);
}

static int	close_cross(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit (1);
	return (1);
}

void	commands(t_var *data)
{
	//mlx_key_hook(data->win_ptr, change_bg, data);
	mlx_hook(data->win_ptr, 2, 0, playermove, data);
	mlx_hook(data->win_ptr, 17, 0, close_cross, data);
	mlx_hook(data->win_ptr, 3, 0, quitgame, data);
}
