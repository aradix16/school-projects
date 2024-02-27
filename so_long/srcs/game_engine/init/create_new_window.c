/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:49:50 by aradix            #+#    #+#             */
/*   Updated: 2024/02/27 18:45:58 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define GAME_NAME "so_long"

int	round_value(int value)
{
	value = (value / TILE_SIZE) * TILE_SIZE;
	if (value % 100 != TILE_SIZE)
		value -= TILE_SIZE;
	return (value);
}

void	get_window_size(t_mlx *mlx, t_window *window, t_map *map)
{
	int	x;
	int	y;

	mlx_get_screen_size(mlx->ptr, &x, &y);
	y -= 100;
	if ((map->size.x * TILE_SIZE) < x)
		x = map->size.x * TILE_SIZE;
	if ((map->size.y * TILE_SIZE) < y)
		y = (map->size.y * TILE_SIZE);
	x = round_value(x);
	y = round_value(y);
	window->size.x = x;
	window->size.y = y;
}

bool	create_new_window(t_mlx *mlx, t_window *window, t_map *map)
{
	mlx->window = window;
	get_window_size(mlx, window, map);
	window->ptr = mlx_new_window(mlx->ptr,
			window->size.x, window->size.y, GAME_NAME);
	return (window->ptr);
}
