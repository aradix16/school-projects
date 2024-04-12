/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_boundaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:20:06 by aradix            #+#    #+#             */
/*   Updated: 2024/04/10 12:28:21 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/* NEED TO IMPROVE READABILITY */
/* DO NOT USE FLOAT HERE ? */

float	get_boundarie(int window_size, int map_size, int current_position)
{
	float	half;
	float	b;

	if ((map_size * TILE_SIZE) <= window_size)
		return (0);
	half = window_size / 2;
	b = current_position - half;
	if (b < 0)
		b = 0;
	else if ((b + window_size) > (map_size * TILE_SIZE))
		b = (map_size * TILE_SIZE) - window_size;
	return (b);
}

void	get_boundaries(t_game *game, t_graphics *graphics)
{
	t_coordinate	boundaries;

	boundaries.x = get_boundarie(graphics->window->size.x, game->map->size.x,
			game->player->pos.x);
	boundaries.y = get_boundarie(graphics->window->size.y, game->map->size.y,
			game->player->pos.y);
	graphics->window->boundaries = boundaries;
}
