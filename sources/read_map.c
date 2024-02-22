/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:10:49 by albertini         #+#    #+#             */
/*   Updated: 2024/02/22 16:50:43 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char **readmap(char *filename)
{
    int fd;
    char *buf;
    char *line;
    char **map;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    while (1)
    {
        buf = get_next_line(fd);
        if (buf == NULL)
            break;
        line = ft_strjoin(line, buf);
		free(buf);
    }
    map = ft_split(line, '\n');
	free(line);
    return (map);
}