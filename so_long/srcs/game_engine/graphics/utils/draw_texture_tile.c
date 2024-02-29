/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_tile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:19:53 by aradix            #+#    #+#             */
/*   Updated: 2024/02/28 16:20:30 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_texture_tile(t_game *game, t_coordinate start_pos, int *texture_data)
{
	int	pos;
	int	x;
	int	y;
	int	tex_pos;
	int	pxl_color;

	pos = (start_pos.y * game->mlx->window->size.x) + start_pos.x;
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			tex_pos = (y * TILE_SIZE) + x;
			pxl_color = texture_data[tex_pos];
			if (pxl_color != 0)
				game->mlx->frame->data[pos] = pxl_color;
			pos++;
			x++;
		}
		pos += game->mlx->window->size.x - TILE_SIZE;
		y++;
	}
}
