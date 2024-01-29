/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:23:25 by aradix            #+#    #+#             */
/*   Updated: 2024/01/29 19:27:07 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	save_map_data(t_game *game, int data, size_t data_index)
{
	if (data == 'E')
	{
		if (game->exit_position)
			return (DUPLICATE_EXIT);
		game->exit_position = data_index;
	}
	else if (data == 'P')
	{
		if (game->player_position)
			return (DUPLICATE_PLAYER);
		game->player_position = data_index;
	}
	else if (data == 'C')
		++game->collectibles_count;
	return (0);
}

short	inner_line_checker(t_game *game, t_map *map, char *line)
{
	short	err;
	size_t	i;
	size_t	map_index;

	i = 0;
	map_index = (map->cols + 1) * map->rows;
	if (line[i] != WALL)
		return (MAP_NOT_CLOSED);
	while (line[i] != '\n')
	{
		if (line[i] == COLLECTIBLE || line[i] == EXIT || line[i] == PLAYER)
		{
			err = save_map_data(game, line[i], map_index + i);
			if (err)
				return (err);
		}
		else if (line[i] != WALL && line[i] != EMPTY)
			return (INVALID_MAP_CHARACTER);
		++i;
	}
	if (i != map->cols)
		return (INVALID_LINE_SIZE);
	if (line[i - 1] != '1')
		return (MAP_NOT_CLOSED);
	return (0);
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
	return (0);
}

short	validity_checker(t_game *game, char *map)
{
	short	err;

	if (!map)
		return (CANNOT_READ_MAP_FILE);
	game->map->map = map;
	err = boundary_line_checker(game->map, map);
	if (err)
		return (err);
	map += game->map->cols + 1;
	while (*(map + (game->map->cols + 1)) && *(map + (game->map->cols + 2)))
	{
		++game->map->rows;
		err = inner_line_checker(game, game->map, map);
		if (err)
			return (err);
		map += game->map->cols + 1;
	}
	err = boundary_line_checker(game->map, map);
	if (err)
		return (err);
	game->map->rows += 2;
	return (0);
}
