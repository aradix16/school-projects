/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 23:04:42 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 23:44:53 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// print new move
int	move_player(t_game *game, int step)
{
	size_t	new_position;

	new_position = game->state->player_position + step;
	if (game->map->ptr[new_position] == '1')
		return (1);
	if (game->map->ptr[new_position] == 'C')
		game->state->collectibles_count--;
	game->map->ptr[game->state->player_position] = '0';
	game->map->ptr[new_position] = 'P';
	game->state->player_position += step;
	printf("%s\n", game->map->ptr);
	return (0);
}
