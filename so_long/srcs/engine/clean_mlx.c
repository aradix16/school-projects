/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:23:15 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 21:52:42 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	clean_mlx(t_mlx *mlx, short state)
{
	if (state == SUCCESS || state > MLX_WINDOW_FAILED)
		mlx_destroy_window(mlx->ptr, mlx->window->ptr);
	if (state == 0 || state > MLX_INIT_FAILED)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	return (state);
}
