
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playability.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:39:17 by aradix            #+#    #+#             */
/*   Updated: 2024/01/25 22:38:35 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	explore(t_map m, char *map, size_t i)
{
	if (map[i] == WALL)
		return (false);
	if (map[i] == EXIT)
		return (true);
	map[i] = WALL;
	if (explore(m, map, i + 1)
			|| explore(m, map, i - 1)
			|| explore(m, map, i + (m.col + 1)) 
			|| explore(m, map, i - (m.col + 1)))
		return (true);
	return (false);
}


short	check_map_playability(t_map *m)
{
	char	*tmp;

	if (!m->exit_position)
		return (NO_EXIT_FOUND);
	if (!m->player_position)
		return (NO_PLAYER_FOUND);
	tmp = ft_strdup(m->map);
	if (!tmp)
		return (1); // MALLOC ERROR
	short ret = explore(*m, tmp, m->player_position);
	printf("--->%d\n", ret);
	printf("\n\n%s\n", tmp);
	return (0);
}
