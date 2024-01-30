/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:42:41 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 23:44:48 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_update(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->window->ptr, mlx->image->ptr, 0, 0);
	return (0);
}

int	on_key_release(int key, t_game *game)
{
	(void)key;
	(void)game;
	return (0);
}

int	on_key_press(int key, t_game *game)
{
	if (key == ESC)
		return (stop_loop(game));
	if (key == UP)
		return (move_player(game, -(game->map->cols + 1)));
	if (key == DOWN)
		return (move_player(game, game->map->cols + 1));
	if (key == LEFT)
		return (move_player(game, -1));
	if (key == RIGHT)
		return (move_player(game, 1));
	render(game);
	return (0);
}
