/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_tile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:29:35 by aradix            #+#    #+#             */
/*   Updated: 2024/04/12 13:29:42 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

#define LEFT 0
#define RIGHT 1
#define UP_LEFT 2
#define UP_RIGHT 3
#define DOWN_LEFT 4
#define DOWN_RIGHT 5

void	draw_texture_tile(t_game *game, t_coordinate start_pos,
		int *texture_data, short facing)
{
	int	pos;
	int	pxl_color;
	int	x;
	int	y;
	int	tex_pos;

	pos = (start_pos.y * game->graphics->window->size.x) + start_pos.x;
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			if (facing == LEFT)
				tex_pos = (y * TILE_SIZE) + x;
			else if (facing == RIGHT)
				tex_pos = (y * TILE_SIZE) + (TILE_SIZE - 1 - x);
			else if (facing == UP_LEFT)
				tex_pos = ((TILE_SIZE - 1 - x) * TILE_SIZE) + y;
			else if (facing == UP_RIGHT)
				tex_pos = (x * TILE_SIZE) + y;
			else if (facing == DOWN_LEFT)
				tex_pos = (x * TILE_SIZE) + (TILE_SIZE - 1 - y);
			else if (facing == DOWN_RIGHT)
				tex_pos = ((TILE_SIZE - 1 - x) * TILE_SIZE) + (TILE_SIZE - 1
						- y);
			pxl_color = texture_data[tex_pos];
			if (pxl_color != 0)
				game->graphics->frame->data[pos] = pxl_color;
			pos++;
			x++;
		}
		pos += game->graphics->window->size.x - TILE_SIZE;
		y++;
	}
}
