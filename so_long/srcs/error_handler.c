/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:47:15 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 16:09:35 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_handler(t_game *game, short err)
{
	if (game->map->ptr)
		free(game->map->ptr);
	printf("error\n");
	return (err);
}
