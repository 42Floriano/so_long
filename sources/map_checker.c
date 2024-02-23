/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:15 by falberti          #+#    #+#             */
/*   Updated: 2024/02/23 18:46:37 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_rectangle_and_nempty(char **map)
{
	int	y;
	int	x;
	int	ok;

	y = 0;
	x = 0;
	ok = 0;
	while (map[y])
		while (map[y][x])
			if (map[y][x] != '0' && map[y][x] != '1')
				ok = 1;
			x++;
		y++;
	if (y >= x)
		return (0);
	y = 0;
	x = 0;
	while (map[y++])
		if (strlen(map[y]) == strlen(map[0]))
			return (0);
	return (1 * ok);
}

static int	closed_by_walls(char **map)
{
	int	y;
	int	x;
	int	len_x;

	y = 0;
	x = 0;
	len_x = ft_strlen(map[0]);
	while (map[y])
		y++;
	while (map[0][x])
		if (map[0][x] != '1' && map[y - 1] != '1')
			return (0);
		x++;
	y = 0;
	while (map[y])
		if (map[y][0] != '1' || map[y][len_x] != '1')
			return (0);
		y++;
	return (1);
}

static int	is_there_epc(char **map)
{
	int	y;
	int	x;
	int	e;
	int	p;
	int	c;

	y = 0;
	x = 0;
	e = 0;
	p = 0;
	c = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				e++;
			if (map[y][x] == 'P')
				p++;
			if (map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	if (e != 1 || p != 1 || c <= 0)
		return (0);
	return (1);
}

// must be changed with game instead
int	map_checkers(char **map)
{
	if (!is_rectangle_and_nempty(map)
		|| !closed_by_walls(map)
		|| !is_there_epc(map))
		return (0);
	return (1);
}