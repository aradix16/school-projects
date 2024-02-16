/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:11:50 by aradix            #+#    #+#             */
/*   Updated: 2024/02/15 16:20:02 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* IF == WALL */
/* 	round si a lorigine le player = 1.00 et qu'il monte  */
/* 	et que on est a 0.80 (donc 0 si on round), mettre le player a 1.0 */

void	update_player_position(t_map *map, t_state *state, t_pos updated_pos)
{
	updated_pos.x += state->player.x;
	updated_pos.y += state->player.y;
	if (map->content[(size_t)updated_pos.x][(size_t)updated_pos.y] == WALL)
		return ;
	if (map->content[(size_t)updated_pos.x][(size_t)updated_pos.y] == EXIT)
		return ;
	map->content[(size_t)state->player.x][(size_t)state->player.y] = EMPTY;
	map->content[(size_t)updated_pos.x][(size_t)updated_pos.y] = PLAYER;
	state->player = updated_pos;
}
