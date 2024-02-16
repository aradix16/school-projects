/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playability.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:39:47 by aradix            #+#    #+#             */
/*   Updated: 2024/02/12 11:25:56 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	explore(t_game *game, char **map, char *check, t_pos pos)
{
	char	c;

	c = map[(size_t)pos.x][(size_t)pos.y];
	if ((c == EXIT || game->state->exit)
		&& game->state->collectibles_count == 0)
		return (true);
	if (c == WALL || check[(size_t)(pos.x * game->map->width + pos.y)] == WALL)
		return (false);
	if (c == COLLECTIBLE)
		--game->state->collectibles_count;
	else if (c == EXIT)
	{
		game->state->exit = true;
		return (false);
	}
	check[(size_t)(pos.x * game->map->width + pos.y)] = '1';
	return (explore(game, map, check, (t_pos){pos.x + 1, pos.y})
		|| explore(game, map, check, (t_pos){pos.x - 1, pos.y}) || explore(game,
			map, check, (t_pos){pos.x, pos.y + 1}) || explore(game, map, check,
			(t_pos){pos.x, pos.y - 1}));
}

short	check_map_playability(t_game *game, t_map *map, t_state *state)
{
	char			*check;
	unsigned int	save;

	check = ft_strnew(map->width * map->height, '0');
	if (!check)
		return (MALLOC_ERROR);
	state->exit = false;
	save = state->collectibles_count;
	if (!explore(game, map->content, check, state->player))
		return (free(check), UNPLAYABLE_MAP);
	free(check);
	state->collectibles_count = save;
	return (SUCCESS);
}
