/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:03:02 by aradix            #+#    #+#             */
/*   Updated: 2024/01/29 09:50:06 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_stuff()
{
	void *mlx;

	mlx = mlx_init();
}


void	init_struct(t_game *game)
{
	game->cols = 0;
	game->rows = 0;
	game->collectibles_count = 0;
	game->exit_position = 0;
	game->player_position = 0;
}

int	main(int ac, char **av)
{
	short	err;
	t_game	game;

	init_struct(&game);
	err = parsing(&game, ac, av);
	if (err)
		return (printf("err\n"));
	mlx_stuff();
	return (0);
}

