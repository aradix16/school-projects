/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:24:03 by aradix            #+#    #+#             */
/*   Updated: 2024/03/18 19:39:26 by aradix           ###   ########.fr       */
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
