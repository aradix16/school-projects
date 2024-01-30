/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:03:02 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 20:57:54 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game, t_map *map, t_state *state)
{
	map->ptr = NULL;
	map->cols = 0;
	map->rows = 0;
	state->player_position = 0;
	state->exit_position = 0;
	state->collectibles_count = 0;
	game->map = map;
	game->state = state;
}

int	main(int ac, char **av)
{
	short	err;
	t_game	game;
	t_map	map;
	t_state	state;

	init_struct(&game, &map, &state);
	err = parsing(&game, ac, av);
	if (err)
		return (error_handler(&game, err));
	err = start_engine(&game);
	if (err)
		return (error_handler(&game, err));
	free(map.ptr);
	return (SUCCESS);
}
