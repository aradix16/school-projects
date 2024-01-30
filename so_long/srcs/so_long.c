/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:03:02 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 13:30:17 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game, t_map *map)
{
	map->cols = 0;
	map->rows = 0;
	game->map = map;
	game->collectibles_count = 0;
	game->exit_position = 0;
	game->player_position = 0;
}

int	main(int ac, char **av)
{
	short	err;
	t_game	game;
	t_map	map;

	init_struct(&game, &map);
	err = parsing(&game, ac, av);
	if (err)
		return (printf("err\n"));
	err = start_engine(&game);
	if (err)
		return (printf("err2\n"));

	/* free(map.map); */
	return (0);
}
