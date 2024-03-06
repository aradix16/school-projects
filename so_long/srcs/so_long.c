/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:59:41 by aradix            #+#    #+#             */
/*   Updated: 2024/03/06 15:46:49 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game, t_map *map, t_player *player)
{
	game->map = map;
	game->player = player;
	game->exit = false;
	game->n_collectibles = 0;
}

int	main(int ac, char **av)
{
	short		err;
	t_game		game;

	init_struct(&game, &(t_map){}, &(t_player){});
	err = parsing(&game, ac, av);
	if (err)
		return (print_error(err));
	err = start_game_engine(&game);
	ft_mtrxfree(game.map->content);
	if (err)
		return (print_error(err));
	return (SUCCESS);
}
