/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:56:37 by aradix            #+#    #+#             */
/*   Updated: 2024/02/15 16:18:09 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press_event(int key, t_game *game)
{
	if (key == ESC)
		return (stop_game_loop(game));
	if (key == UP)
		update_player_position(game->map, game->state, (t_pos){-1, 0});
	else if (key == DOWN)
		update_player_position(game->map, game->state, (t_pos){1, 0});
	else if (key == LEFT)
		update_player_position(game->map, game->state, (t_pos){0, -1});
	else if (key == RIGHT)
		update_player_position(game->map, game->state, (t_pos){0, 1});
	draw_frame(game, game->mlx->frame);
	render_frame(game->mlx);
	return (0);
}
