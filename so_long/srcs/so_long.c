/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:59:41 by aradix            #+#    #+#             */
/*   Updated: 2024/02/26 18:22:03 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game, t_map *map)
{
	game->player = (t_coordinate){0, 0};
	game->n_collectibles = 0;
	game->exit = false;
	map->size = (t_coordinate){0, 0};
	game->map = map;
}

int	main(int ac, char **av)
{
	short	err;
	t_game	game;
	t_map	map;

	init_struct(&game, &map);
	err = parsing(&game, ac, av);
	if (err)
		return (print_error(err));
	err = start_game_engine(&game);
	if (err)
		return (print_error(err));
	ft_mtrxfree(map.content);
	return (SUCCESS);
}
