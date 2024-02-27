/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:18:45 by aradix            #+#    #+#             */
/*   Updated: 2024/02/26 17:58:55 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	check_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != OBSTACLE)
			return (INVALID_MAP);
		i++;
	}
	return (SUCCESS);
}

short	save_map_data(t_game *game, int data, size_t x, size_t y)
{
	if (data == 'P')
	{
		if (game->player.x)
			return (INVALID_MAP);
		game->player.x = x;
		game->player.y = y;
	}
	else if (data == 'E')
	{
		if (game->exit)
			return (INVALID_MAP);
		game->exit = true;
	}
	else if (data == 'C')
		++game->n_collectibles;
	return (SUCCESS);
}

short	check_line(t_game *game, char *line, int y, int expected_x)
{
	int		x;
	short	err;

	x = 0;
	if (line[x] != OBSTACLE)
		return (INVALID_MAP);
	while (++x < expected_x)
	{
		if (line[x] == PLAYER || line[x] == COLLECTIBLE || line[x] == EXIT)
		{
			err = save_map_data(game, line[x], x, y);
			if (err)
				return (err);
		}
		else if (line[x] != GROUND && line[x] != OBSTACLE)
			return (INVALID_MAP);
	}
	if (x != expected_x || line[x - 1] != OBSTACLE)
		return (INVALID_MAP);
	return (SUCCESS);
}

short	check_map_validity(t_game *game, t_map *map)
{
	short	err;
	int		y;

	y = 0;
	while (y < map->size.y)
	{
		err = check_line(game, map->content[y], y, map->size.x);
		if (err)
			return (err);
		++y;
	}
	if (game->player.x == 0 || !game->exit || game->n_collectibles < 1)
		return (INVALID_MAP);
	err = check_last_line(map->content[y - 1]);
	if (err)
		return (err);
	return (SUCCESS);
}
