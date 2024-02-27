/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_display_connection.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:32:54 by aradix            #+#    #+#             */
/*   Updated: 2024/02/26 15:02:42 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	initialize_display_connection(t_game *game, t_mlx *mlx)
{
	game->mlx = mlx;
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (false);
	return (true);
}
