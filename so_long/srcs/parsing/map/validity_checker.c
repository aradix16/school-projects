/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:22:43 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 18:51:32 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	save_map_data(t_state *state, int data, size_t data_index)
{
	if (data == 'P')
	{
		if (state->player_position)
			return (DUPLICATE_PLAYER);
		state->player_position = data_index;
	}
	else if (data == 'E')
	{
		if (state->exit_position)
			return (DUPLICATE_EXIT);
		state->exit_position = data_index;
	}
	else if (data == 'C')
		++state->collectibles_count;
	return (SUCCESS);
}

short	inner_line_checker(t_map *map, t_state *state, char *line)
{
	short	err;
	char	*tmp;

	if (*line != WALL)
		return (MAP_NOT_CLOSED);
	tmp = line;
	while (*line && *line != '\n')
	{
		if (*line == PLAYER || *line == COLLECTIBLE || *line == EXIT)
		{
			err = save_map_data(state, *line, line - map->ptr);
			if (err)
				return (err);
		}
		else if (*line != WALL && *line != EMPTY)
			return (INVALID_MAP_CHARACTER);
		++line;
	}
	if ((size_t)(line - tmp) != map->cols)
		return (INVALID_LINE_SIZE);
	if (*(line - 1) != '1')
		return (MAP_NOT_CLOSED);
	return (SUCCESS);
}

short	boundary_line_checker(t_map *map, char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != WALL)
			return (MAP_NOT_CLOSED);
		++i;
	}
	if (map->cols == 0)
		map->cols = i;
	if (i < 3 || map->cols != i)
		return (INVALID_LINE_SIZE);
	return (SUCCESS);
}

short	validity_checker(t_map *map, t_state *state, char *map_content)
{
	short	err;

	if (!map_content)
		return (CANNOT_READ_MAP_FILE);
	map->ptr = map_content;
	err = boundary_line_checker(map, map_content);
	if (err)
		return (err);
	while (*(map_content + map->cols) && *(map_content + (map->cols + 1)))
	{
		++map->rows;
		map_content += map->cols + 1;
		err = inner_line_checker(map, state, map_content);
		if (err)
			return (err);
	}
	err = boundary_line_checker(map, map_content);
	if (err)
		return (err);
	return (SUCCESS);
}
