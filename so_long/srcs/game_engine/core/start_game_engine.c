/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:22:02 by aradix            #+#    #+#             */
/*   Updated: 2024/04/10 10:32:17 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

short	start_game_engine(t_game *game)
{
	t_graphics	graphics;
	t_textures	textures;
	t_window	window;
	t_mlx_img	frame;
	t_sprite	sprite;

	game->graphics = &graphics;
	if (!initialize_display_connection(&graphics))
		return (MLX_INIT_FAILED);
	if (!load_textures(&graphics, &textures))
		return (clean_mlx(&graphics, LOAD_TEXTURES_FAILED));
	if (!create_new_window(&graphics, &window, game->map->size))
		return (clean_mlx(&graphics, MLX_WINDOW_FAILED));
	if (!create_new_frame_buffer(&graphics, &frame, graphics.window->size))
		return (clean_mlx(&graphics, MLX_IMAGE_FAILED));


    // init here ?? 
    game->graphics->sprite = &sprite;
    sprite.t0 = get_current_time();
    sprite.p0 = sprite.t0;
    sprite.state = 1;
    sprite.is_moving = false;
    sprite.right_facing = false;
    game->player->pos.x *= TILE_SIZE;
    game->player->pos.y *= TILE_SIZE;
    game->graphics->sprite->step = (t_coordinate){0, 0};
    //  render(game); ??


	start_game_loop(game, &graphics);
	return (clean_mlx(game->graphics, SUCCESS));
}
