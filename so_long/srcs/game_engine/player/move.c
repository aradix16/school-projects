/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:25:33 by aradix            #+#    #+#             */
/*   Updated: 2024/04/12 15:01:55 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

bool	player_move(t_game *game)
{
	const int		move_timeout = 10;
	const int		dist = 3;
	t_coordinate	new_pos;

	if (!timeout(game->graphics->sprite->t0, move_timeout))
		return (false);
	new_pos.x = game->player->pos.x + (game->graphics->sprite->step.x * dist);
	new_pos.y = game->player->pos.y + (game->graphics->sprite->step.y * dist);
	game->player->pos = new_pos;
	game->graphics->sprite->t0 = get_current_time();
    return (true);
}
