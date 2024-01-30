/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:28:35 by falberti          #+#    #+#             */
/*   Updated: 2024/01/30 18:13:24 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == 53)
	{
		printf("The %d key (ESC) has been pressed\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		//mlx_destroy_image(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit (1);
	}
	sleep(1);
	printf("The %d key has been pressed\n", keysym);
	return (0);
}

void	color_screen(t_mlx_data *data, int color)
{
	while (i < SIDE_LEN)
}

int	change_bg(int keysum, t_mlx_data *data)
{
	if (keysum == KEYCODE_R)
		color_screen()
	return (0);
}

// int	change_color(t_mlx_data *data)
// {
// 	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 150, data->color, "Changing color");
// 	if(data->color == 0xFF0000)
// 		data->color = 0x0FF000;
// 	else if (data->color == 0x0FF000)
// 		data->color = 0x0000FF;
// 	else
// 		data->color = 0xFF0000;
// 	return (0);
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Hello world!");
	data.color = 0xFF0000;
	if (data.win_ptr == NULL)
	{
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop_hook(data.mlx_ptr, change_bg, &data);
	//img.img = mlx_new_image(mlx_connection, 800, 600);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	//								&img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 550, 300, 0x00FF0000);
	//mlx_put_image_to_window(mlx_connection, mlx_win, img.img, 0, 0);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
}
