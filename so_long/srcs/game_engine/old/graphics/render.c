/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:00:27 by aradix            #+#    #+#             */
/*   Updated: 2024/02/29 13:00:04 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	CODE LOGIC HERE
	- if animation (maybe rename render->animation_state) == 0
		- return ;
	- if animation == true && delay_for_next_render <= current time
		- render_player
		- increment bonudaries to TILE_SIZE / N_PLAYER
		- add next +X secondes to next_render

	IN PLAYER EVENT
	- if animation == true || next_pos == WALL
		- return ;
	- animation = true
	- initialise t0 to current_time
	- get_boundaries and store in struct
*/

void	render_frame(t_mlx *mlx, t_mlx_img *frame)
{
	mlx_put_image_to_window(mlx->ptr, mlx->window->ptr, frame->image, 0, 0);
}

int	render(t_game *game)
{
	const int		target_ms = 120;
	int				target_diff;
	t_nsec			current_time;
	t_coordinate	tmp;
	t_coordinate	start;

	if (game->player_animation->state > 3)
		return (0);
	current_time = get_current_time();
	if (game->player_animation->state == 0)
	{
		tmp.x = get_boundaries(game->player.x, game->mlx->window->size.x,
				game->map->size.x);
		tmp.y = get_boundaries(game->player.y, game->mlx->window->size.y,
				game->map->size.y);
		start.x = (game->player.x * TILE_SIZE) - tmp.x;
		start.y = (game->player.y * TILE_SIZE) - tmp.y;
		game->player_animation->move = start;
	}
	else
	{
		target_diff = get_diff_ms(current_time, game->player_animation->t0);
		if (target_diff < target_ms)
			return (0);
		if (game->player_animation->state == 3)
			game->player_animation->move.x -= 15;
		else
			game->player_animation->move.x -= 16;

	}
	game->player_animation->t0 = current_time;
	draw_map(game);
	draw_player(game, game->player_animation->move);
	render_frame(game->mlx, game->mlx->frame);


	if (game->player_animation->state == 3)
		game->player.x -= 1;
	game->player_animation->state++;
	return (0);
}

void	prerender(t_game *game, t_animation *player_animation)
{
	player_animation->state = 0;
	player_animation->move = (t_coordinate){0, 0};
	game->player_animation = player_animation;
}
