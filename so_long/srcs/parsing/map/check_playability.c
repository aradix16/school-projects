/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playability.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:00:10 by aradix            #+#    #+#             */
/*   Updated: 2024/01/26 15:01:06 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	explore(t_game *game, char *map, size_t i)
{
	if (game->exit_position == 0 && game->collectibles_count == 0)
		return (true);
	if (map[i] == WALL)
		return (false);
	if (map[i] == COLLECTIBLE)
		game->collectibles_count--;
	else if (map[i] == EXIT)
		game->exit_position = 0;
	map[i] = WALL;
	if (explore(game, map, i + 1)
		|| explore(game, map, i - 1)
		|| explore(game, map, i + (game->cols + 1))
		|| explore(game, map, i - (game->cols + 1)))
		return (true);
	return (false);
}

short	check_map_playability(t_game game)
{
	char	*tmp;

	if (game.collectibles_count < 1)
		return (NO_COLLECTIBLE_FOUND);
	if (!game.exit_position)
		return (NO_EXIT_FOUND);
	if (!game.player_position)
		return (NO_PLAYER_FOUND);
	tmp = ft_strdup(game.map);
	if (!tmp)
		return (MALLOC_ERROR);
	if (!explore(&game, tmp, game.player_position))
	{
		free(tmp);
		return (UNPLAYABLE_MAP);
	}
	free(tmp);
	return (0);
}
