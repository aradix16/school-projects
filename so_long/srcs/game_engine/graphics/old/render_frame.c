/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:40:39 by aradix            #+#    #+#             */
/*   Updated: 2024/02/26 20:42:06 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_frame(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr,
		mlx->window->ptr, mlx->frame->image, 0, 0);
	return (0);
}
