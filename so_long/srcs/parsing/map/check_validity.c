/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:21:18 by aradix            #+#    #+#             */
/*   Updated: 2024/02/10 21:21:43 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	save_map_data(int data, size_t x, size_t y, t_state *state)
{
	if (data == 'P')
	{
		if (state->player.x)
			return (DUPLICATE_PLAYER);
		state->player.x = x;
		state->player.y = y;
	}
	else if (data == 'E')
	{
		if (state->exit)
			return (DUPLICATE_EXIT);
		state->exit = true;
	}
	else if (data == 'C')
		++state->collectibles_count;
	return (SUCCESS);
}

short	check_line(char *line, size_t x, size_t width, t_state *state)
{
	short	err;
	size_t	y;

	if (line[0] != WALL)
		return (INVALID_MAP_CONTENT);
	y = 1;
	while (line[y])
	{
		if (line[y] == PLAYER || line[y] == COLLECTIBLE || line[y] == EXIT)
		{
			err = save_map_data(line[y], x, y, state);
			if (err)
				return (err);
		}
		else if (line[y] != EMPTY && line[y] != WALL)
			return (INVALID_MAP_CONTENT);
		++y;
	}
	if (y != width || line[y - 1] != WALL)
		return (INVALID_MAP_CONTENT);
	return (SUCCESS);
}

short	check_last_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != WALL)
			return (INVALID_MAP_CONTENT);
		i++;
	}
	return (SUCCESS);
}

short	check_map_validity(t_map *map, t_state *state)
{
	short	err;
	size_t	x;

	x = 1;
	while (map->content[x])
	{
		err = check_line(map->content[x], x, map->width, state);
		if (err)
			return (err);
		++x;
	}
	if (state->player.x == 0 || !state->exit || state->collectibles_count < 1)
		return (INVALID_MAP_CONTENT);
	err = check_last_line(map->content[x - 1]);
	if (err)
		return (err);
	return (SUCCESS);
}
