/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:39:00 by aradix            #+#    #+#             */
/*   Updated: 2024/02/01 14:06:16 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_window_size(t_mlx *mlx, t_window *window, t_map *map)
{
	int	width;
	int	height;

	mlx_get_screen_size(mlx->ptr, &width, &height);
	if ((map->cols * TILE_SIZE) < ((size_t)width))
		width = map->cols * TILE_SIZE;
	if ((map->rows * TILE_SIZE) < ((size_t)height))
		height = map->rows * TILE_SIZE;
	window->width = width;
	window->height = height;
}

bool	create_window(t_mlx *mlx, t_window *window, t_map *map)
{
	mlx->window = window;
	get_window_size(mlx, window, map);
	window->ptr = mlx_new_window(mlx->ptr, window->width, window->height,
			"so_long");
	return (window->ptr);
}
