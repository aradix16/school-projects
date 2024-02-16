/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:41:47 by aradix            #+#    #+#             */
/*   Updated: 2024/02/15 17:20:03 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game, t_map *map, t_state *state)
{
	map->content = NULL;
	map->width = 0;
	map->height = 0;
	game->map = map;
	state->player.x = 0;
	state->player.y = 0;
	state->exit = false;
	state->collectibles_count = 0;
	game->state = state;
	*game->seed = 0;
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
		return (print_error(err));
	err = start_engine(&game);
	if (err)
		return (ft_mtrxfree(map.content), print_error(err));
	ft_mtrxfree(map.content);
	return (SUCCESS);
}
