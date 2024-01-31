/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:56:37 by aradix            #+#    #+#             */
/*   Updated: 2024/01/31 15:18:06 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_event(t_game *game)
{
	(void)game;
	/* mlx_put_image_to_window(mlx->ptr, mlx->window->ptr, */
			/* mlx->frame->image, 0, 0); */
	// check if player get all collectibles
	// check if player reached exit /* stop_game_loop(game); */
	//
	// // re render ??
	return (SUCCESS);
}

int	key_press_event(int key, t_game *game)
{
	if (key == ESC)
		return (stop_game_loop(game));
	if (key == UP)
		update_player_position(game, -(game->map->cols + 1));
	else if (key == DOWN)
		update_player_position(game, game->map->cols + 1);
	else if (key == LEFT)
		update_player_position(game, -1);
	else if (key == RIGHT)
		update_player_position(game, 1);
	render(game, game->mlx->frame);
	return (SUCCESS);
}
