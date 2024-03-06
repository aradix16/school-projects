/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:22:02 by aradix            #+#    #+#             */
/*   Updated: 2024/03/06 15:55:39 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	start_game_engine(t_game *game)
{
	t_graphics	graphics;

	game->graphics = &graphics;
	if (!initialize_display_connection(&graphics))
		return (MLX_INIT_FAILED);
	if (!load_textures(&graphics, &(t_textures){}))
		return (clean_mlx(&graphics, LOAD_TEXTURES_FAILED));



	/* if (!create_new_window(&mlx, &window, game->map)) */
	/* 	return (clean_mlx(&mlx, MLX_WINDOW_FAILED)); */
	/* if (!create_new_frame(&mlx, &frame, &window)) */
	/* 	return (clean_mlx(&mlx, MLX_IMAGE_FAILED)); */
	/**/
	/**/
	/* t_coordinate player; */
	/* player.x = game->player.x * TILE_SIZE; */
	/**/
	/* t_coordinate tmp; */
	/**/
	/* tmp.x = get_boundaries2(game->mlx->window->size.x, game->map->size.x,
			player.x); */
	/**/
	/* printf("%d\n", player.x - tmp.x); */
	/**/
	/**/
	/**/
	/**/
	/**/
	/**/
	/**/
	/**/
	/**/
	/**/
	/**/
	/* prerender(game, &render); */
	/* printf("expected player pos = %d\n", game->render->move.x); */
	/**/
	/* start_game_loop(game, &mlx); */
	return (clean_mlx(&graphics, SUCCESS));
}
