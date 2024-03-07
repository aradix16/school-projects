/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:33:15 by aradix            #+#    #+#             */
/*   Updated: 2024/03/06 20:42:40 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	render_frame(t_mlx *mlx, t_mlx_img *frame) */
/* { */
/* 	mlx_put_image_to_window(mlx->ptr, mlx->window->ptr, frame->image, 0, 0); */
/* } */
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
/* void	prerender(t_game *game, t_render *render) */
/* { */
/* 	game->render = render; */
/* 	game->render->animation_state = 1; */
/* 	game->render->key_press = false; */
/* 	game->render->t0 = get_current_time(); */
/* 	init(game); */
/* 	draw_map(game); */
/* 	draw_player(game); */
/* 	render_frame(game->mlx, game->mlx->frame); */
/* } */

void	first_render(t_game *game, t_graphics *graphics)
{

	(void)game;
	(void)graphics;
}
