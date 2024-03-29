/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:30:09 by falberti          #+#    #+#             */
/*   Updated: 2024/03/12 14:18:23 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
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
	void		*img_enemy;
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

// Fucntions prototypes in order of use
void				init_struct(t_game *g);
char				**readmap(char *filename);
char				**ft_split(char const *s, char c);
int					map_checkers(t_game *game, char *path);
int					is_map_valid(t_game *game, char *path);
int					init_game(t_game *game);
void				draw_map(t_game *g);
void				commands(t_game *data);
void				playermove(int keycode, t_game *vars);
void				exit_game(t_game *game);
void				free_map(char **map);
void				draw_score(t_game *g);

#endif