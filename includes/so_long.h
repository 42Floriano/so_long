/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:30:09 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 09:49:43 by albertini        ###   ########.fr       */
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

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	void		*img_bg;
	void		*img_wall;
	void		*img_pu;
	void		*img_pd;
	void		*img_c;
	void		*img_exit;
	int			map_w;
	int			map_h;
	int			img_w;
	int			img_h;
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
	int			exit_ok;
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
void				init_struct(t_game *g);
void				draw_map(t_game *g);

#endif