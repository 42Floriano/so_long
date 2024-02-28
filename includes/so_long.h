/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:30:09 by falberti          #+#    #+#             */
/*   Updated: 2024/02/28 14:06:17 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include "hook.h"
# include "mlx.h"
# include "libftmini/libft.h"

// Definition of the structure
typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bit_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			player_x;
	int			player_y;
	int			player_score;
	int			player_moves;
	int			exit_portal;
	int			entry_portal;
	int			nb_eatable;
	int			max_y;
	int			max_x;
	int			y;
	int			x;
	int			exit_checker;
	int			eat_checker;
	bool 		exit_ok;
	t_img		img;
}				t_game;

void				commands(t_game *data);
void				color_screen(t_game *data, int color);
char				**readmap(char *filename);
int					playermove(int keycode, t_game *vars);
int					map_checkers(t_game *game, char *path);
int					is_map_valid(t_game *game, char *path);
void				free_map(char **map);
void				init_game(t_game *game);
void				exit_game(t_game *game);
char				**ft_split(char const *s, char c);

#endif