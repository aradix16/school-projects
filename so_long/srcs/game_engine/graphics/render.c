/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:33:15 by aradix            #+#    #+#             */
/*   Updated: 2024/03/12 15:06:41 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_frame(t_graphics *graphics)
{
	mlx_put_image_to_window(graphics->mlx_ptr, graphics->window->ptr,
		graphics->frame->image, 0, 0);
}

/**/
/* void	render(t_game *game) */
/* { */
/* 	render_frame(game->mlx, game->mlx->frame); */
/* } */
/**/
/* void	init(t_game *game) */
/* { */
/* 	t_coordinate	tmp; */
/* 	t_coordinate	start; */
/**/
/* 	tmp.x = get_boundaries(game->player.x, game->mlx->window->size.x, */
/* 			game->map->size.x); */
/* 	tmp.y = get_boundaries(game->player.y, game->mlx->window->size.y, */
/* 			game->map->size.y); */
/* 	start.x = (game->player.x * TILE_SIZE) - tmp.x; */
/* 	start.y = (game->player.y * TILE_SIZE) - tmp.y; */
/* 	game->render->move = start; */
/* } */
/**/

void	first_render(t_game *game, t_graphics *graphics)
{
	graphics->t0 = get_current_time();
	game->player->pos.x *= TILE_SIZE;
	game->player->pos.y *= TILE_SIZE;
	get_boundaries(game, graphics);
	draw_map(game);
	render_frame(graphics);
}

/*
boundaries.x = game->player->pos.x - get_boundaries(graphics->window->size.x,
		game->map->size.x, game->player->pos.x);
boundaries.y = game->player->pos.y - get_boundaries(graphics->window->size.y,
		game->map->size.y, game->player->pos.y);
*/
