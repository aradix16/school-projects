/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:36:35 by aradix            #+#    #+#             */
/*   Updated: 2024/02/27 18:47:39 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	get_texture_size(int i, int start, int stop, int offset)
{
	if (i == start)
		return (TILE_SIZE - offset);
	else if (i + TILE_SIZE >= stop)
		return (stop - i);
	return (TILE_SIZE);
}

t_area	set_area(t_coordinate offset, t_coordinate size)
{
	/* return ((t_area){ */
	/* 	offset, */
	/* 	(t_coordinate){offset.x + size.x, offset.y + size.y} */
	/* }); */
	return ((t_area){
		(t_coordinate){offset.x, 0},
		(t_coordinate){offset.x + size.x, size.y}
	});
}

int	draw_map_row(t_game *game, t_coordinate start, t_coordinate stop, int y)
{
	t_coordinate	index;
	t_coordinate	offset;
	t_coordinate	size;
	int				x;
	t_area			texture_area;

	index.y = y / TILE_SIZE;
	offset.y = y % TILE_SIZE;
	size.y = get_texture_size(y, start.y, stop.y, offset.y);
	x = start.x;
	while (x < stop.x)
	{
		index.x = x / TILE_SIZE;
		offset.x = x % TILE_SIZE;
		size.x = get_texture_size(x, start.x, stop.x, offset.x);
		texture_area = set_area(offset, size);
		draw_tile(
			game,
			(t_coordinate){(x - start.x), (y - start.y)},
			texture_area,
			game->mlx->textures->ground[0].data);

		if (game->map->content[index.y][index.x] == OBSTACLE)
		{
			draw_tile(
				game,
				(t_coordinate){(x - start.x), (y - start.y)},
				texture_area,
				game->mlx->textures->obstacle[0].data);
		}
		/* draw_sprite(game, index); */
		x += size.x;
	}
	printf("\n");
	return (TILE_SIZE);
}

void	draw_frame(t_game *game)
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
