/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:31:44 by aradix            #+#    #+#             */
/*   Updated: 2024/01/29 21:50:58 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_window_size(t_window *window, t_mlx *mlx, t_map *map)
{
	int	x;
	int	y;

	mlx_get_screen_size(mlx->ptr, &x, &y);
	if (map->rows < ((size_t)x * TILE_SIZE))
		x = map->rows * TILE_SIZE;
	if (map->cols < ((size_t)y * TILE_SIZE))
		y = map->cols * TILE_SIZE;
	window->y = y;
	window->x = x;
}

bool	create_window(t_window *window, t_mlx *mlx, t_map *map)
{
	set_window_size(window, mlx, map);
	mlx->window = mlx_new_window(mlx->ptr, window->y, window->x, "so_long");
	if (!mlx->window)
		return (false);
	return (true);
}
