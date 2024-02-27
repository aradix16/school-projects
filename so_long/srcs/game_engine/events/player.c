/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:16:43 by aradix            #+#    #+#             */
/*   Updated: 2024/02/27 17:16:24 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_position(t_game *game, t_map *map,
		t_coordinate updated_position)
{
	updated_position.x += game->player.x;
	updated_position.y += game->player.y;
	
	int i = 0;
	printf("\n");
	while (game->map->content[i])
	{
		printf("%s\n", game->map->content[i]);
		i++;
	}
	printf("\n");


	if (map->content[updated_position.y][updated_position.x] == OBSTACLE)
		return ;
	if (map->content[updated_position.y][updated_position.x] == EXIT)
		return ;
	map->content[game->player.y][game->player.x] = GROUND;
	map->content[updated_position.y][updated_position.x] = PLAYER;
	game->player = updated_position;
}
