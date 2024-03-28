
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:33:15 by aradix            #+#    #+#             */
/*   Updated: 2024/03/28 11:42:52 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_game *game)
{
	get_boundaries(game, game->graphics);
	draw_map(game);
	draw_player(game);
	mlx_put_image_to_window(game->graphics->mlx_ptr,
		game->graphics->window->ptr, game->graphics->frame->image, 0, 0);
}

void	prerender(t_game *game, t_sprite *sprite)
{
	game->graphics->sprite = sprite;
	sprite->t0 = get_current_time();
	sprite->p0 = get_current_time();
	sprite->state = 1;
	sprite->is_moving = false;
	sprite->right_facing = false;
	game->player->pos.x *= TILE_SIZE;
	game->player->pos.y *= TILE_SIZE;
	printf("y = %d, x = %d\n", game->player->pos.y, game->player->pos.x);
	game->graphics->sprite->step = (t_coordinate){0, 0};
	render(game);
}
