/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:21:31 by aradix            #+#    #+#             */
/*   Updated: 2024/02/27 19:33:34 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_image(t_mlx *mlx, t_mlx_img *texture, int n)
{
	while (--n >= 0)
	{
		if (texture[n].image != NULL)
			mlx_destroy_image(mlx->ptr, texture[n].image);
	}
}

void	clean_textures(t_mlx *mlx, t_textures *textures)
{
	clean_image(mlx, textures->ground, N_GROUND);
	clean_image(mlx, textures->obstacle, N_OBSTACLE);
	clean_image(mlx, textures->player, N_PLAYER);
	clean_image(mlx, textures->collectible, N_COLLECTIBLE);
}
