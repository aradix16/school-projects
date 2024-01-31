/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:47:19 by aradix            #+#    #+#             */
/*   Updated: 2024/01/31 14:45:49 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	clean_mlx(t_mlx *mlx, short state)
{
	if (state == SUCCESS || state > MLX_WINDOW_FAILED)
		mlx_destroy_window(mlx->ptr, mlx->window->ptr);
	if (state == 0 || state > MLX_IMAGE_FAILED)
		mlx_destroy_image(mlx->ptr, mlx->frame->image);
	if (state == 0 || state > MLX_INIT_FAILED)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	return (state);
}
