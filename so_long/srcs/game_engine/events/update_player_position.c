/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:16:43 by aradix            #+#    #+#             */
/*   Updated: 2024/02/29 12:59:27 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	CODE LOGIC HERE
	- the logic must be divided in 3 part:
		- 1 update player_moving state
		- 2 animate
		- 3 check new position
			- deal with counter, exit and collectibles

	(so maybe the fucntiom below could be move player (maybe in a dedicated folder),
	and the second function could be update_player_position
*/

void	update_player_position(t_game *game, t_map *map, t_coordinate move)
{
	t_coordinate	updated_position;

	/* if (game->player_animation->state ) */
	updated_position.x = game->player.x + move.x;
	updated_position.y = game->player.y + move.y;
	if (map->content[updated_position.y][updated_position.x] == OBSTACLE)
		return ;
	game->player_animation->move = move;
	game->player_animation->state = 0;
}
