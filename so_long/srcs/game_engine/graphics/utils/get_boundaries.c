/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_boundaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:53:55 by aradix            #+#    #+#             */
/*   Updated: 2024/02/27 17:43:03 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

float	get_boundaries(int player_pos, int window_size, int map_size)
{
	float	half;
	float	b;

	if ((map_size * TILE_SIZE) <= window_size)
		return (0);
	half = window_size / 2;
	b = ((player_pos * TILE_SIZE) + (TILE_SIZE / 2)) - half;
	if (b < 0)
		b = 0;
	else if ((b + window_size) > (map_size * TILE_SIZE))
		b = (map_size * TILE_SIZE) - window_size;
	return (b);
}
