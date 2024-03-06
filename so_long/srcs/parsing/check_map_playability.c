/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_playability.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:00:14 by aradix            #+#    #+#             */
/*   Updated: 2024/03/06 15:19:49 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	explore(t_game *game, char **map, char *check, t_coordinate player)
{
	char	c;

	c = map[player.y][player.x];
	if ((c == EXIT || game->exit) && game->n_collectibles == 0)
		return (true);
	if (c == OBSTACLE
		|| check[(player.y * game->map->size.x + player.x)] == OBSTACLE)
		return (false);
	if (c == COLLECTIBLE)
		--game->n_collectibles;
	else if (c == EXIT)
	{
		game->exit = true;
		return (false);
	}
	check[(player.y * game->map->size.x + player.x)] = '1';
	return (explore(game, map, check, (t_coordinate){player.x + 1, player.y})
		|| explore(game, map, check, (t_coordinate){player.x - 1, player.y})
		|| explore(game, map, check, (t_coordinate){player.x, player.y + 1})
		|| explore(game, map, check, (t_coordinate){player.x, player.y - 1})
	);
}

short	check_map_playability(t_game *game, t_map *map)
{
	char	*check;
	int		save;

	check = ft_strnew(map->size.x * map->size.y, '0');
	if (!check)
		return (MALLOC_ERROR);
	game->exit = false;
	save = game->n_collectibles;
	if (!explore(game, map->content, check, game->player->pos))
		return (free(check), UNPLAYABLE_MAP);
	free(check);
	game->n_collectibles = save;
	return (SUCCESS);
}
