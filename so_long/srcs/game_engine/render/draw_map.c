/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:48:22 by aradix            #+#    #+#             */
/*   Updated: 2024/02/28 16:56:44 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_item(t_game *game, t_coordinate index, t_coordinate start_pos)
{
	char	c;

	draw_texture_tile(game, start_pos, game->mlx->textures->ground[0].data);
	c = game->map->content[index.y][index.x];
	if (c == OBSTACLE)
		draw_texture_tile(game, start_pos, game->mlx->textures->obstacle[0].data);
	else if (c == COLLECTIBLE)
		draw_texture_tile(game, start_pos, game->mlx->textures->collectible[1].data);
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

	start.x = get_boundaries(game->player.x, game->mlx->window->size.x,
			game->map->size.x);
	start.y = get_boundaries(game->player.y, game->mlx->window->size.y,
			game->map->size.y);
	stop.x = start.x + game->mlx->window->size.x;
	stop.y = start.y + game->mlx->window->size.y;
	y = start.y;
	while (y < stop.y)
	{
		draw_map_row(game, start, stop, y);
		y += TILE_SIZE;
	}
}
