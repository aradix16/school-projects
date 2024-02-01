/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playability_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:54:19 by aradix            #+#    #+#             */
/*   Updated: 2024/02/01 16:02:09 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	explore(t_state *state, char *map, size_t i, const size_t cols)
{
	if ((map[i] == EXIT || state->exit_position == 0)
			&& state->collectibles_count == 0)
		return (true);
	if (map[i] == WALL)
		return (false);
	if (map[i] == COLLECTIBLE)
		--state->collectibles_count;
	else if (map[i] == EXIT)
	{
		state->exit_position = 0;
		return (false);
	}
	map[i] = WALL;
	if (explore(state, map, i + 1, cols)
		|| explore(state, map, i - 1, cols)
		|| explore(state, map, i + (cols + 1), cols)
		|| explore(state, map, i - (cols + 1), cols))
		return (true);
	return (false);
}

short	playability_checker(t_map *map, t_state state)
{
	char	*cpy;

	if (state.collectibles_count < 1)
		return (NO_COLLECTIBLE_FOUND);
	if (!state.exit_position)
		return (NO_EXIT_FOUND);
	if (!state.player_position)
		return (NO_PLAYER_FOUND);
	cpy = ft_strdup(map->ptr);
	if (!cpy)
		return (MALLOC_ERROR);
	if (!explore(&state, cpy, state.player_position, map->cols))
	{
		free(cpy);
		printf("UNPLAYABLE");
		return (UNPLAYABLE_MAP);
	}
	free(cpy);
	return (SUCCESS);
}
