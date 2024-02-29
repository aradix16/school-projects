/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:10:50 by aradix            #+#    #+#             */
/*   Updated: 2024/02/28 14:46:16 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation(t_game *game, t_coordinate updated_position)
{
	/* game->map->content[game->player.y][game->player.x] = GROUND; */
	/* game->map->content[updated_position.y][updated_position.x] = PLAYER; */

	game->player = updated_position;


	t_coordinate tmp;
	t_coordinate start;

	tmp.x = get_boundaries(game->player.x, game->mlx->window->size.x, game->map->size.x);
	tmp.y = get_boundaries(game->player.y, game->mlx->window->size.y, game->map->size.y);



	// animation be like
	start.x = (game->player.x * TILE_SIZE) - tmp.x;
	start.y = (game->player.y * TILE_SIZE) - tmp.y;
	draw_tile(game, start, game->mlx->textures->player[1].data);
	render_frame(game->mlx);


	start.x += 25;
	draw_tile(game, start, game->mlx->textures->player[1].data);
	render_frame(game->mlx);

	start.x += 25;
	draw_tile(game, start, game->mlx->textures->player[1].data);
	render_frame(game->mlx);
}
