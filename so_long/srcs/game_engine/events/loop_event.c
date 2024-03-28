/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:58:25 by aradix            #+#    #+#             */
/*   Updated: 2024/03/28 12:31:00 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sleep_anim(t_game *game, t_nsec current_time)
{
	int	target_diff;

	if (game->graphics->sprite->state == 0)
		return (0);
	target_diff = get_diff_ms(current_time, game->graphics->sprite->t0);
	if (target_diff < 1000)
		return (0);
	game->graphics->sprite->state = 0;
	render(game);
	return (0);
}

/* bool check_pos(t_game *game, int pixels_to_move) */
/* { */
/* 	t_coordinate tmp;  */
/* 	t_coordinate pos; */
/**/
/*     tmp = game->player->pos; */
/*     tmp.x += pixels_to_move; */
/**/
/* 	tmp.y += (TILE_SIZE / 2); */
/**/
/* 	if (pixels_to_move > 0) */
/* 		tmp.x += TILE_SIZE; */
/* 	pos.x = tmp.x / TILE_SIZE; */
/* 	pos.y = tmp.y / TILE_SIZE; */
/**/
/* 	if (game->map->content[pos.y][pos.x] == OBSTACLE) */
/* 			 return (false); */
/* 	return (true); */
/* } */
/**/
/* bool check_pos_y(t_game *game, int pixels_to_move) */
/* { */
/*     t_coordinate tmp;  */
/*     t_coordinate pos; */
/**/
/*     tmp = game->player->pos; */
/*     tmp.y += pixels_to_move; */
/**/
/* 	tmp.x += (TILE_SIZE / 2); */
/**/
/* 	if (pixels_to_move > 0) */
/* 		tmp.y += TILE_SIZE; */
/**/
/*     pos.x = tmp.x / TILE_SIZE; */
/*     pos.y = tmp.y / TILE_SIZE; */
/**/
/*     if (game->map->content[pos.y][pos.x] == OBSTACLE) */
/*         return (false); */
/**/
/*     return (true); */
/* } */
/**/
/* bool	player_move(t_game *game, t_nsec current_time) */
/* { */
/* 	int	target_diff; */
/* 	int	pixels_to_move; */
/**/
/* 	target_diff = get_diff_ms(current_time, game->graphics->sprite->p0); */
/* 	if (target_diff < 30) */
/* 		return (false); */
/**/
/**/
/* 	game->graphics->sprite->p0 = current_time; */
/**/
/* 	pixels_to_move = 5; */
/* 	if (game->graphics->sprite->step.x != 0) */
/* 	{ */
/* 		pixels_to_move *= game->graphics->sprite->step.x; */
/* 		if (check_pos(game, pixels_to_move)) */
/* 			game->player->pos.x += pixels_to_move; */
/* 	} */
/* 	else if (game->graphics->sprite->step.y != 0) */
/* 	{ */
/* 		pixels_to_move *= game->graphics->sprite->step.y; */
/* 		if (check_pos_y(game, pixels_to_move)) */
/* 			game->player->pos.y += pixels_to_move; */
/* 	} */
/* 	return (true); */
/* } */

t_coordinate	get_next_tile_pos(t_game *game, const int move_dist)
{
	return ((t_coordinate){
		game->player->pos.x + (game->graphics->sprite->step.x * move_dist),
		game->player->pos.y + (game->graphics->sprite->step.y * move_dist),
	});
}


bool check_obstacle(t_game *game, t_coordinate pos)
{
	/* if (game->graphics->sprite->step.x > 0) */
	/* { */
	/* 	if (game->map->content[(pos.y + 25) / TILE_SIZE][(pos.x + TILE_SIZE) / TILE_SIZE] == OBSTACLE) */
	/* 		return (true); */
	/* } */
	/* else if (game->graphics->sprite->step.x < 0) */
	/* { */
	/* 	if (game->map->content[(pos.y + 25) / TILE_SIZE][pos.x / TILE_SIZE] == OBSTACLE) */
	/* 		return (true); */
	/* } */
	/**/
	/**/
	/* if (game->graphics->sprite->step.y > 0 && game->graphics->sprite->right_facing) */
	/* { */
	/* 	if (game->map->content[(pos.y + 40) / TILE_SIZE][(pos.x + 10)/ TILE_SIZE] == OBSTACLE) */
	/* 		return (true); */
	/* } */
	/* else if (game->graphics->sprite->step.y > 0) */
	/* 	if (game->map->content[(pos.y + 40) / TILE_SIZE][(pos.x + 30)/ TILE_SIZE] == OBSTACLE) */
	/* 		return (true); */
	/**/
	/* if (game->graphics->sprite->step.y < 0 && game->graphics->sprite->right_facing) */
	/* { */
	/* 	if (game->map->content[(pos.y) / TILE_SIZE][(pos.x + 10)/ TILE_SIZE] == OBSTACLE) */
	/* 		return (true); */
	/* } */
	/* else if (game->graphics->sprite->step.y < 0) */
	/* 	if (game->map->content[(pos.y) / TILE_SIZE][(pos.x + 30)/ TILE_SIZE] == OBSTACLE) */
	/* 		return (true); */


	// top left 
	t_coordinate top_left = pos;
	top_left.x += 20;
	top_left.y += 20;
	if (game->map->content[top_left.y / TILE_SIZE][top_left.x / TILE_SIZE] == OBSTACLE)
	{
		printf("top left\n");
		return (true);
	}
	// top right 
	t_coordinate top_right = (t_coordinate){pos.x + TILE_SIZE, pos.y};
	top_right.x -= 20;
	top_right.y += 20;
	if (game->map->content[top_right.y / TILE_SIZE][top_right.x / TILE_SIZE] == OBSTACLE)
	{
		printf("top right\n");
		return (true);
	}
	// bottom left
	t_coordinate bottom_left = (t_coordinate){pos.x, pos.y + TILE_SIZE};
	bottom_left.x += 20;
	bottom_left.y -= 20;
	if (game->map->content[bottom_left.y / TILE_SIZE][bottom_left.x / TILE_SIZE] == OBSTACLE)
	{
		printf("bottom left\n");
		return (true);
	}
	// bottom right
	t_coordinate bottom_right = (t_coordinate){pos.x + TILE_SIZE, pos.y};
	bottom_right.x -= 20;
	bottom_right.y += 20;
	if (game->map->content[bottom_right.y / TILE_SIZE][bottom_right.x / TILE_SIZE] == OBSTACLE)
	{
		printf("bottom right\n");
		return (true);
	}
	return (false);
}

char	get_next_tile_value(t_game *game, const int move_dist)
{
	t_coordinate	tmp;
	t_coordinate	pos;

	tmp = get_next_tile_pos(game, move_dist);
	if (check_obstacle(game, tmp))
		return (OBSTACLE);


	pos.x = tmp.x / TILE_SIZE;
	pos.y = tmp.y / TILE_SIZE;
	return ('x');

	// top right / bottom right / top left / bottom left
	
	/* tmp.y += (TILE_SIZE / 2); */
	/* if (game->graphics->sprite->step.x > 0) */
		/* tmp.x += TILE_SIZE; */
	/* else if (game->graphics->sprite->step.y > 0) */
	/* 	tmp.y += TILE_SIZE; */
}

bool	player_move_timeout(t_game *game, t_nsec current_time)
{
	int	target_diff;

	target_diff = get_diff_ms(current_time, game->graphics->sprite->p0);
	if (target_diff < 30)
		return (false);
	game->graphics->sprite->p0 = current_time;
	return (true);
}

bool	player_move(t_game *game, t_nsec current_time)
{
	char		tile_value;
	const int	move_dist = 5;

	if (!player_move_timeout(game, current_time))
		return (false);
	tile_value = get_next_tile_value(game, move_dist);
	if (tile_value == OBSTACLE)
		return (false);
	game->player->pos = get_next_tile_pos(game, move_dist);
	return (true);
}

bool	sprite_anim(t_game *game, t_nsec current_time)
{
	int	target_diff;

	target_diff = get_diff_ms(current_time, game->graphics->sprite->t0);
	if (target_diff < 130)
		return (false);
	game->graphics->sprite->t0 = current_time;
	game->graphics->sprite->state++;
	if (game->graphics->sprite->state == 3)
		game->graphics->sprite->state = 1;
	return (true);
}

int	on_mlx_loop(t_game *game)
{
	t_nsec	current_time;

	current_time = get_current_time();
	if (!game->graphics->sprite->is_moving)
		return (sleep_anim(game, current_time));
	if (sprite_anim(game, current_time) || player_move(game, current_time))
		render(game);
	return (0);
}
