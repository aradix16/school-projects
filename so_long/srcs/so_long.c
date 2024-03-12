/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:59:41 by aradix            #+#    #+#             */
/*   Updated: 2024/03/12 15:42:30 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game, t_map *map, t_player *player)
{
	game->map = map;
	game->player = player;
	game->exit = false;
	game->n_collectibles = 0;
	map->content = NULL;
	map->size = (t_coordinate){0, 0};
	player->pos = (t_coordinate){0, 0};
}

int	main(int ac, char **av)
{
	short		err;
	t_game		game;
	t_map		map;
	t_player	player;

	init_struct(&game, &map, &player);
	err = parsing(&game, ac, av);
	if (err)
		return (print_error(err));
	err = start_game_engine(&game);
	ft_mtrxfree(game.map->content);
	if (err)
		return (print_error(err));
	return (SUCCESS);
}


/*
TODO:
	- deal with state animation (0 sleep, 1 walk-a, 2 walk-b)
	- update boundaries on each player move 
	- check if player stay on the map 
	- check for collectbles / exit 
	- "randomness" with textures (ground, obstacles, collectibles)
	- not sure about the "waking up" animation:
	basic animation:
	0			25			50 
	[State1]	[State2]	[State1]	

	from sleep state: 
	0			0			25 			50
	[State 0]	[State1]	[State2]	[State1]
	
	- restructure with a graphics->animation-> ... (t0, state, ...)
	- find a good texture for the exit 
	- count player steps
	- maybe move the code from "player" in "events" because all the player moving logic is inside the render/animation code logic
	- add "killer mushroom" and the "dead player" texture + state (3)
*/
