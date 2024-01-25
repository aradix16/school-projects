/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:03:02 by aradix            #+#    #+#             */
/*   Updated: 2024/01/25 16:19:41 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->map = NULL;
	game->map_x = 0;
	game->map_y = 0;
	game->map_size = 0;
	game->e_pos = 0;
	game->p_pos = 0;
	game->c_counter = 0;
}

int	main(int ac, char **av)
{
	t_game	game;
	short	err;

	init_struct(&game);
	err = parsing(&game, ac, av);
	if (err)
	{
		if (game.map)
			free(game.map);
		return (print_error(err));
	}
	free(game.map);
	return (0);
}
