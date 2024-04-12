/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:08:25 by aradix            #+#    #+#             */
/*   Updated: 2024/04/12 15:03:42 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	on_mlx_loop(t_game *game)
{ 
	if (game->graphics->sprite->is_moving)
	{
		if (player_move(game) || player_animation(game))
	        render(game, true);
	}
	else if (player_sleep(game))
	    render(game, true);
	return (0);
}

#define ESC 65307
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

int	on_key_press(int key, t_game *game)
{
	if (key == ESC)
		return (stop_game_loop(game));
	if (key == UP)
		game->graphics->sprite->step = (t_coordinate){0, -1};
	else if (key == DOWN)
		game->graphics->sprite->step = (t_coordinate){0, 1};
	else if (key == LEFT)
		game->graphics->sprite->step = (t_coordinate){-1, 0};
	else if (key == RIGHT)
		game->graphics->sprite->step = (t_coordinate){1, 0};
	else
	{
		game->graphics->sprite->is_moving = false;
		return (0);
	}
	game->graphics->sprite->is_moving = true;
	return (0);
}

int	on_key_release(int key, t_game *game)
{
	(void)key;
	game->graphics->sprite->is_moving = false;
	return (0);
}
