/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:49:50 by aradix            #+#    #+#             */
/*   Updated: 2024/03/06 20:10:36 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WINDOW_TITLE "so_long"

int	round_value(int value)
{
	value = (value / TILE_SIZE) * TILE_SIZE;
	if (value % 100 != TILE_SIZE)
		value -= TILE_SIZE;
	return (value);
}

void	get_window_size(void *mlx_ptr, t_window *window, t_coordinate map_size)
{
	int	x;
	int	y;

	mlx_get_screen_size(mlx_ptr, &x, &y);
	x = round_value(x);
	y = round_value(y - 100);
	if ((map_size.x * TILE_SIZE) < x)
		x = map_size.x * TILE_SIZE;
	if ((map_size.y * TILE_SIZE) < y)
		y = (map_size.y * TILE_SIZE);
	window->size.x = x;
	window->size.y = y;
}

bool	create_new_window(t_graphics *graphics, t_window *window,
		t_coordinate map_size)
{
	graphics->window = window;
	get_window_size(graphics->mlx_ptr, window, map_size);
	window->ptr = mlx_new_window(graphics->mlx_ptr, window->size.x,
			window->size.y, WINDOW_TITLE);
	return (window->ptr);
}
