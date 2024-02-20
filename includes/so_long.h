/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:30:09 by falberti          #+#    #+#             */
/*   Updated: 2024/02/20 16:08:55 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "hook.h"
# include "mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx_data {
	t_data	*mlx_ptr;
	t_data	*win_ptr;
	int		color;

}				t_mlx_data;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bit_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_var
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_var;

void				commands(t_var *data);
void				color_screen(t_var *data, int color);

#endif