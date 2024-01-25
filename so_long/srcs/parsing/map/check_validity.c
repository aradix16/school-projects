/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:23:25 by aradix            #+#    #+#             */
/*   Updated: 2024/01/25 19:36:56 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	save_map_data(t_map *m, int c, size_t c_position)
{
	if (c == 'E')
	{
		if (m->exit_position)
			return (DUPLICATE_EXIT);
		m->exit_position = c_position;
	}
	else if (c == 'P')
	{
		if (m->player_position)
			return (DUPLICATE_PLAYER);
		m->player_position = c_position;
	}
	else if (c == 'C')
		++m->collectibles;
	return (0);
}

short	check_inner_line(t_map *m, char *line)
{
	short	err;
	size_t	i;
	size_t	map_position;

	i = 0;
	map_position = (m->col + 1) * m->row;
	if (line[i] != WALL)
		return (MAP_NOT_CLOSED);
	while (line[i] != '\n')
	{
		if (line[i] == COLLECTIBLE || line[i] == EXIT || line[i] == PLAYER)
		{
			err = save_map_data(m, line[i], map_position + i);
			if (err)
				return (err);
		}
		else if (line[i] != WALL && line[i] != EMPTY)
			return (INVALID_MAP_CHARACTER);
		++i;
	}
	if (i != m->col)
		return (INVALID_LINE_SIZE);
	if (line[i - 1] != '1')
		return (MAP_NOT_CLOSED);
	return (0);
}

short	check_boundary_line(t_map *m, char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != WALL)
			return (MAP_NOT_CLOSED);
		++i;
	}
	if (m->col == 0)
		m->col = i;
	if (i < 3 || m->col != i)
		return (INVALID_LINE_SIZE);
	return (0);
}

short	check_map_validity(t_map *m, char *map)
{
	short	err;

	if (!map)
		return (CANNOT_READ_MAP_FILE);
	m->map = map;
	err = check_boundary_line(m, map);
	if (err)
		return (err);
	map += m->col + 1;
	while (*(map + (m->col + 1)) && *(map + (m->col + 2)))
	{
		++m->row;
		err = check_inner_line(m, map);
		if (err)
			return (err);
		map += m->col + 1;
	}
	err = check_boundary_line(m, map);
	if (err)
		return (err);
	m->row += 2;
	return (0);
}
