/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:21:31 by aradix            #+#    #+#             */
/*   Updated: 2024/03/06 15:53:38 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_image(void *mlx_ptr, t_mlx_img *texture, int n)
{
	while (--n >= 0)
	{
		if (texture[n].image != NULL)
			mlx_destroy_image(mlx_ptr, texture[n].image);
	}
}

void	clean_textures(t_graphics *graphics, t_textures *textures)
{
	clean_image(graphics->mlx_ptr, textures->ground, N_GROUND);
	clean_image(graphics->mlx_ptr, textures->obstacle, N_OBSTACLE);
	clean_image(graphics->mlx_ptr, textures->player, N_PLAYER);
	clean_image(graphics->mlx_ptr, textures->collectible, N_COLLECTIBLE);
}
