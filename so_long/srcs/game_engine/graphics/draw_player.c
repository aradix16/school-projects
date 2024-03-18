/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:52:07 by aradix            #+#    #+#             */
/*   Updated: 2024/03/18 21:12:06 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *game)
{
	int id;
	t_coordinate start;

	start.x = game->player->pos.x - game->graphics->window->boundaries.x;
	start.y = game->player->pos.y - game->graphics->window->boundaries.y;

	id = game->graphics->sprite->state;
	draw_texture_tile(game, start, game->graphics->textures->player[id].data);
}
