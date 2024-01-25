/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:23:25 by aradix            #+#    #+#             */
/*   Updated: 2024/01/25 16:27:31 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	save_map_data(t_game *game, int c, size_t pos)
{
	if (c == 'E')
	{
		if (game->e_pos != 0)
			return (false);
		game->e_pos = pos;
	}
	else if (c == 'P')
	{
		if (game->p_pos != 0)
			return (false);
		game->p_pos = pos;
	}
	else if (c == 'C')
		++game->c_counter;
	return (true);
}

bool	is_inner_line_valid(t_game *game, char *map, size_t pos)
{
	size_t	i;

	i = 0;
	if (map[i] != '1')
		return (false);
	while (map[i] != '\n')
	{
		if (ft_strchr("CEP", map[i]) != NULL)
		{
			if (!save_map_data(game, map[i], pos + i))
				return (false);
		}
		else if (map[i] != '0' && map[i] != '1')
			return (false);
		++i;
	}
	return (i == game->map_x && map[i - 1] == '1');
}

bool	is_boundary_line_valid(t_game *game, char *map)
{
	size_t	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if (map[i] != '1')
			return (false);
		++i;
	}
	if (game->map_x == 0)
		game->map_x = i;
	return (i >= 3 && game->map_x == i);
}

bool	is_map_valid(t_game *game)
{
	size_t	i;

	if (!is_boundary_line_valid(game, game->map))
		return (false);
	i = game->map_x + 1;
	game->map_size = ft_strlen(game->map, '\0');
	while (game->map[i + game->map_x] && game->map[i + game->map_x + 1])
	{
		if (!is_inner_line_valid(game, game->map + i, i))
			return (false);
		i += game->map_x + 1;
	}
	if (game->c_counter < 1)
		return (false);
	if (!is_boundary_line_valid(game, game->map + i))
		return (false);
	return (true);
}
