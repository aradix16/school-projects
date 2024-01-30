/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:56:33 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 12:21:19 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	load_textures(t_texture *texture, t_mlx *mlx)
{
	texture->ptr = mlx_xpm_file_to_image(mlx->ptr, WALL_TEXTURE,
			&texture->width, &texture->height);
	if (!texture->ptr)
		return (false);
	if (texture->width != TILE_SIZE || texture->height != TILE_SIZE)
		return (false);
	return (true);
}
