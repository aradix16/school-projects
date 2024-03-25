/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:21:38 by aradix            #+#    #+#             */
/*   Updated: 2024/03/25 11:01:30 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ESC 65307
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

void	stop_player(t_game *game)
{
	game->graphics->sprite->is_moving = false;
}

int	on_key_release(int key, t_game *game)
{
	(void)key;
	stop_player(game);
	return (0);
}

void	move_player(t_game *game, t_coordinate step)
{
	game->graphics->sprite->is_moving = true;
	if (game->graphics->sprite->step.x == 1 )
		game->graphics->sprite->right_facing = true;
	else if (game->graphics->sprite->step.x == -1)
		game->graphics->sprite->right_facing = false;
	game->graphics->sprite->step = step;
}

int	on_key_press(int key, t_game *game)
{
	if (key == ESC)
		return (stop_game_loop(game->graphics));
	if (key == UP)
		move_player(game, (t_coordinate){0, -1});
	else if (key == DOWN)
		move_player(game, (t_coordinate){0, 1});
	else if (key == LEFT)
		move_player(game, (t_coordinate){-1, 0});
	else if (key == RIGHT)
		move_player(game, (t_coordinate){1, 0});
	return (0);
}
