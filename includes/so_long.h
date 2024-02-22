/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:30:09 by falberti          #+#    #+#             */
/*   Updated: 2024/02/22 17:19:30 by albertini        ###   ########.fr       */
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
# include <fcntl.h>

// Definition of the global variable
extern int nb_moves;

// Definition of the structure
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
	char		**map;
	int			player_x;
	int			player_y;
	int			player_score;
	int			nb_eatable;
	bool 		exit;
	t_img		img;
}				t_var;

void				commands(t_var *data);
void				color_screen(t_var *data, int color);
char				**readmap(char *filename);

#endif