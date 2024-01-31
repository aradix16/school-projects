/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:56:37 by aradix            #+#    #+#             */
/*   Updated: 2024/01/31 19:05:04 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press_event(int key, t_game *game)
{
	if (key == ESC)
		return (stop_game_loop(game));
	if (key == UP)
		update_player_position(game->map, game->state, -(game->map->cols + 1));
	else if (key == DOWN)
		update_player_position(game->map, game->state, game->map->cols + 1);
	else if (key == LEFT)
		update_player_position(game->map, game->state, -1);
	else if (key == RIGHT)
		update_player_position(game->map, game->state, 1);
	if (check_player_position(game->map, game->state))
		return (stop_game_loop(game));
	/* draw_frame(game, game->mlx->frame); */
	render_frame(game->mlx);
	return (0);
}
