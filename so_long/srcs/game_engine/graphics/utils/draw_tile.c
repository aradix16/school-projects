/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:35:27 by aradix            #+#    #+#             */
/*   Updated: 2024/02/27 14:45:10 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *game, t_coordinate start_pos, t_area cpy_area,
		int *texture_data)
{
	int	pos;
	int	x;
	int	y;
	int	tex_pos;
	int	pxl_color;

	pos = (start_pos.y * game->mlx->window->size.x) + start_pos.x;
	y = cpy_area.start.y;
	while (y < cpy_area.stop.y)
	{
		x = cpy_area.start.x;
		while (x < cpy_area.stop.x)
		{
			tex_pos = (y * TILE_SIZE) + x;
			pxl_color = texture_data[tex_pos];
			if (pxl_color != 0)
				game->mlx->frame->data[pos] = pxl_color;
			pos++;
			x++;
		}
		pos += game->mlx->window->size.x - (cpy_area.stop.x - cpy_area.start.x);
		y++;
	}
}
