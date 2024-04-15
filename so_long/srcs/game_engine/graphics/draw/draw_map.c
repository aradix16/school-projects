/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:27:43 by aradix            #+#    #+#             */
/*   Updated: 2024/04/15 17:37:23 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	draw_item(t_game *game, t_coordinate index, t_coordinate start_pos)
{
	char	c;

	draw_texture_tile(game, start_pos, game->graphics->textures->ground[0].data,
		0);
	c = game->map->content[index.y][index.x];
	if (c == OBSTACLE)
		draw_texture_tile(game, start_pos,
			game->graphics->textures->obstacle[0].data, 0);
	else if (c == COLLECTIBLE)
		draw_texture_tile(game, start_pos,
			game->graphics->textures->collectible[0].data, 0);
}

void	draw_map_row(t_game *game, t_coordinate start, t_coordinate stop, int y)
{
	int				x;
	t_coordinate	index;

	x = start.x;
	index.y = y / TILE_SIZE;
	while (x < stop.x)
	{
		index.x = x / TILE_SIZE;
		draw_item(game, index, (t_coordinate){x - start.x, y - start.y});
		x += TILE_SIZE;
	}
}

void	draw_map(t_game *game)
{
	t_coordinate	start;
	t_coordinate	stop;
	int				y;

	start = game->graphics->window->boundaries;
	stop.x = start.x + game->graphics->window->size.x;
	stop.y = start.y + game->graphics->window->size.y;
	y = start.y;
	while (y < stop.y)
	{
		draw_map_row(game, start, stop, y);
		y += TILE_SIZE;
	}
}

void	draw_map_lazy(t_game *game)
{
	t_coordinate	start;
	t_coordinate	index;

	start.x = game->player->pos.x - game->graphics->window->boundaries.x;
	start.y = game->player->pos.y - game->graphics->window->boundaries.y;
    start.x = (start.x / TILE_SIZE) * TILE_SIZE;
    start.y = (start.y / TILE_SIZE) * TILE_SIZE;

    index.x = game->player->pos.x / TILE_SIZE;
    index.y = game->player->pos.y / TILE_SIZE;

    draw_item(game, index, start);
    draw_item(game, (t_coordinate){index.x + 1, index.y}, (t_coordinate){start.x + TILE_SIZE, start.y});
    draw_item(game, (t_coordinate){index.x, index.y + 1}, (t_coordinate){start.x, start.y + TILE_SIZE});
    draw_item(game, (t_coordinate){index.x + 1, index.y + 1}, (t_coordinate){start.x + TILE_SIZE, start.y + TILE_SIZE});
}

