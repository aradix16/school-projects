/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:22:02 by aradix            #+#    #+#             */
/*   Updated: 2024/03/06 22:57:40 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	start_game_engine(t_game *game)
{
	t_graphics	graphics;
	t_textures	textures;
	t_window	window;
	t_mlx_img	frame;

	game->graphics = &graphics;
	if (!initialize_display_connection(&graphics))
		return (MLX_INIT_FAILED);
	if (!load_textures(&graphics, &textures))
		return (clean_mlx(&graphics, LOAD_TEXTURES_FAILED));
	if (!create_new_window(&graphics, &window, game->map->size))
		return (clean_mlx(&graphics, MLX_WINDOW_FAILED));
	if (!create_new_frame_buffer(&graphics, &frame, graphics.window->size))
		return (clean_mlx(&graphics, MLX_IMAGE_FAILED));
	first_render(game, &graphics);
	start_game_loop(game, &graphics);
	return (clean_mlx(game->graphics, SUCCESS));
}

/* t_coordinate player; */
/* player.x = game->player.x * TILE_SIZE; */
/* t_coordinate tmp; */
/* tmp.x = get_boundaries2(game->mlx->window->size.x, game->map->size.x,
		player.x); */
/* printf("%d\n", player.x - tmp.x); */
/* prerender(game, &render); */
/* printf("expected player pos = %d\n", game->render->move.x); */
