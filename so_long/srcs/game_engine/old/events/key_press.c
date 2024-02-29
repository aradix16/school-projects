/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:04:30 by aradix            #+#    #+#             */
/*   Updated: 2024/02/28 15:34:21 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ESC 65307
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

int	handle_key_press(int key, t_game *game)
{
	if (key == ESC)
		return (stop_game_loop(game));
	if (key == UP)
		update_player_position(game, game->map, (t_coordinate){0, -1});
	else if (key == DOWN)
		update_player_position(game, game->map, (t_coordinate){0, 1});
	else if (key == LEFT)
		update_player_position(game, game->map, (t_coordinate){-1, 0});
	else if (key == RIGHT)
		update_player_position(game, game->map, (t_coordinate){1, 0});
	return (0);
}
