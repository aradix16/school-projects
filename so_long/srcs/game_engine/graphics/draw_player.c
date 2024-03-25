/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:52:07 by aradix            #+#    #+#             */
/*   Updated: 2024/03/25 16:01:50 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *game)
{
	int				id;
	t_coordinate	start;
	int				dir;

	start.x = game->player->pos.x - game->graphics->window->boundaries.x;
	start.y = game->player->pos.y - game->graphics->window->boundaries.y;
	id = game->graphics->sprite->state;
	dir = 0;
	if (game->graphics->sprite->step.x == 1)
		dir = 1;
	else if (game->graphics->sprite->step.y == -1)
	{
		dir = 2;
		if (game->graphics->sprite->right_facing)
			dir = 3;
	}
	else if (game->graphics->sprite->step.y == 1)
	{
		dir = 4;
		if (game->graphics->sprite->right_facing)
			dir = 5;
	}
	draw_texture_tile(game, start, game->graphics->textures->player[id].data,
		dir);
}
