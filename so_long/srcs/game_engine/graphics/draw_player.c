/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:52:07 by aradix            #+#    #+#             */
/*   Updated: 2024/03/13 15:32:12 by aradix           ###   ########.fr       */
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
	/* start.x = (game->player.x * TILE_SIZE) - game->render->move.x; */
	/* start.y = (game->player.y * TILE_SIZE) - game->render->move.y; */
	
	/* id = game->render->animation_state; */

	/**/
	/* if (id > 0) */
	/* { */
	/**/
	/* if (id % 2) */
	/* 	id = 2; */
	/* else  */
	/* 	id = 1; */
	/**/
	/* } */

	/* id = game->player_animation->state; */
	/* if (id >= N_PLAYER) */
	/* 	id = 0; */
}

/* int target_ms = 500; */
/* int target_diff = get_diff_ms(t0, t0) + target_ms; */
/**/
/* game->t0 = get_current_time(); */
/* if (move.x == 0 && move.y == 0) */
/* 	return ; */
/* deplay = clock_gettime(CLOCK_MONOTONIC, &game->t0); */
/* printf("%d\n", deplay); */
/* draw_map(game); */
/* start.x -= 17; */
/* draw_texture_tile(game, start, game->mlx->textures->player[1].data); */
/* draw_map(game); */
/* 	start.x -= 17; */
/* 	draw_texture_tile(game, start, game->mlx->textures->player[2].data); */
/* 		draw_map(game); */
/* 	start.x -= 16; */
/* 	draw_texture_tile(game, start, game->mlx->textures->player[0].data); */
/* 	printf("%d\n", start.x); */
/* 	(void)move; */
/* } */

/* (void)game; */
/* 	(void)updated_position; */
/* 	t_coordinate	tmp; */
/* 	t_coordinate	start; */

/* game->map->content[game->player.y][game->player.x] = GROUND; */
/* game->map->content[updated_position.y][updated_position.x] = PLAYER; */

/* game->player = updated_position; */
/* tmp.x = get_boundaries(game->player.x, game->mlx->window->size.x, */
/* 		game->map->size.x); */
/* tmp.y = get_boundaries(game->player.y, game->mlx->window->size.y, */
/* 		game->map->size.y); */
// animation be like
/* start.x = (game->player.x * TILE_SIZE) - tmp.x; */
/* start.y = (game->player.y * TILE_SIZE) - tmp.y; */
/* draw_tile(game, start, game->mlx->textures->player[1].data); */
/* render_frame(game->mlx); */
/* start.x += 25; */
/* draw_tile(game, start, game->mlx->textures->player[1].data); */
/* render_frame(game->mlx); */
/* start.x += 25; */
/* draw_tile(game, start, game->mlx->textures->player[1].data); */
/* render_frame(game->mlx); */
