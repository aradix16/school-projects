/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:08:46 by aradix            #+#    #+#             */
/*   Updated: 2024/02/26 19:40:47 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	clean_mlx(t_mlx *mlx, short state)
{
	if (state == SUCCESS || state >= LOAD_TEXTURES_FAILED)
		clean_textures(mlx, mlx->textures);
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
