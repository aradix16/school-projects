/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:54:00 by aradix            #+#    #+#             */
/*   Updated: 2024/04/10 10:33:33 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	stop_player(t_game *game)
{
	(void)game;
	game->graphics->sprite->is_moving = false;
}

void	move_player(t_game *game, t_coordinate step)
{
	game->graphics->sprite->is_moving = true;
	if (game->graphics->sprite->step.x == 1)
		game->graphics->sprite->right_facing = true;
	else if (game->graphics->sprite->step.x == -1)
		game->graphics->sprite->right_facing = false;
	game->graphics->sprite->step = step;
}
