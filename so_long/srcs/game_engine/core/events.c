/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:08:25 by aradix            #+#    #+#             */
/*   Updated: 2024/04/10 10:12:29 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

#define ESC 65307
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

int	on_mlx_loop(t_game *game)
{
	(void)game;
	/* t_nsec	current_time; */
	/* current_time = get_current_time(); */
	/* if (!game->graphics->sprite->is_moving) */
	/* 	return (sleep_animation(game, current_time)); */
	/* if (move_timeout(game, current_time)) */
	/* 	return (0); */
	/* if (sprite_anim(game, current_time) || player_move(game,
			current_time)) */
	/* 	render(game); */
	return (0);
}

int	on_key_release(int key, t_game *game)
{
	(void)key;
	stop_player(game);
	return (0);
}

int	on_key_press(int key, t_game *game)
{
	if (key == ESC)
		return (stop_game_loop(game));
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
