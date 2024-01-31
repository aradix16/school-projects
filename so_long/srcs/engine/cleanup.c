/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:47:19 by aradix            #+#    #+#             */
/*   Updated: 2024/01/31 18:19:33 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_textures(t_mlx *mlx, t_texture *texture, int i)
{
	while (--i >= 0)
	{
		if (texture[i].image != NULL)
			mlx_destroy_image(mlx->ptr, texture[i].image);
	}
}

short	clean_mlx(t_mlx *mlx, short state)
{
	if (state == SUCCESS || state >= LOAD_TEXTURES_FAILED)
		clean_textures(mlx, mlx->texture, NB_TEXTURES);
	if (state == SUCCESS || state > MLX_WINDOW_FAILED)
		mlx_destroy_window(mlx->ptr, mlx->window->ptr);
	if (state == SUCCESS || state > MLX_IMAGE_FAILED)
		mlx_destroy_image(mlx->ptr, mlx->frame->image);
	if (state == SUCCESS || state > MLX_INIT_FAILED)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	return (state);
}
