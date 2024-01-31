/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:42:41 by aradix            #+#    #+#             */
/*   Updated: 2024/01/31 14:53:08 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_event(t_mlx *mlx);
{
	mlx_put_image_to_window(mlx->ptr, mlx->window->ptr, mlx->image->ptr, 0, 0);
	return (0);
}

int	key_press_event(int key, t_game *game);
{
	if (key == ESC)
		return (stop_game_loop(game));
	/* if (key == UP) */
	/* 	return (move_player(game, -(game->map->cols + 1))); */
	/* if (key == DOWN) */
	/* 	return (move_player(game, game->map->cols + 1)); */
	/* if (key == LEFT) */
	/* 	return (move_player(game, -1)); */
	/* if (key == RIGHT) */
	/* 	return (move_player(game, 1)); */
	/* render(game); */
	return (0);
}
