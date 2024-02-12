/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:28:35 by falberti          #+#    #+#             */
/*   Updated: 2024/02/12 15:03:50 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bit_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == 53)
	{
		printf("The %d key (ESC) has been pressed\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit (1);
	}
	sleep(1);
	printf("The %d key has been pressed\n", keysym);
	return (0);
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

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

int	change_bg(int keysum, t_var *data)
{
	if (keysum == KEYCODE_ESC)
	{
		printf("The %d key (ESC) has been pressed\n", keysum);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit (1);
	}
	if (keysum == KEYCODE_R)
		color_screen(data, encode_rgb(255, 0, 0));
	else if (keysum == KEYCODE_G)
		color_screen(data, encode_rgb(0, 255, 0));
	else if (keysum == KEYCODE_B)
		color_screen(data, encode_rgb(0, 0, 255));
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr,
		data->img.img_ptr, 0, 0);
	return (0);
}

int	change_color(t_mlx_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 150,
		data->color, "Changing color");
	if (data->color == 0xFF0000)
		data->color = 0x0FF000;
	else if (data->color == 0x0FF000)
		data->color = 0x0000FF;
	else
		data->color = 0xFF0000;
	return (0);
}

int	main(void)
{
	t_var	vars;

	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (1);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 800, 800, "Hello world!");
	vars.img.img_ptr = mlx_new_image(vars.mlx_ptr, 800, 800);
	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr,
			&vars.img.bit_per_pixel,
			&vars.img.line_len,
			&vars.img.endian);
	if (vars.win_ptr == NULL)
	{
		mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
		free(vars.mlx_ptr);
		return (1);
	}
	mlx_key_hook(vars.win_ptr, change_bg, &vars);
	mlx_loop(vars.mlx_ptr);
	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
	free(vars.mlx_ptr);
}
