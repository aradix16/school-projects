/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:11:50 by aradix            #+#    #+#             */
/*   Updated: 2024/01/31 15:20:47 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_player_position(t_game *game, size_t direction)
{
	size_t	new_position;

	new_position = game->state->player_position + direction;
	if (game->map->ptr[new_position] == WALL)
		return (1);
	if (game->map->ptr[new_position] == COLLECTIBLE)
		game->state->collectibles_count--;
	game->map->ptr[game->state->player_position] = EMPTY;
	game->map->ptr[new_position] = PLAYER;
	game->state->player_position += direction;
	printf("%s\n", game->map->ptr);
	return (0);
}
