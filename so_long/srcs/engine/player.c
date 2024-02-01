/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:11:50 by aradix            #+#    #+#             */
/*   Updated: 2024/02/01 16:03:35 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_player_position(t_map *map, t_state *state)
{
	if (state->player_position == state->exit_position
		&& state->collectibles_count == 0)
		return (true);
	if (map->ptr[state->player_position] == COLLECTIBLE)
		state->collectibles_count--;
	/* debug only */
	map->ptr[state->player_position] = PLAYER;
	printf("%s\n", map->ptr);
	/* --- */
	return (false);
}

void	update_player_position(t_map *map, t_state *state, size_t direction)
{
	size_t	new_position;

	new_position = state->player_position + direction;
	if (map->ptr[new_position] == WALL)
		return ;
	if (new_position == state->exit_position && state->collectibles_count != 0)
		return ;
	map->ptr[state->player_position] = EMPTY;
	state->player_position = new_position;
}
