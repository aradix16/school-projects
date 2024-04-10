/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:08:46 by aradix            #+#    #+#             */
/*   Updated: 2024/04/10 10:01:50 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

short	clean_mlx(t_graphics *graphics, short state)
{
	if (state == SUCCESS || state >= LOAD_TEXTURES_FAILED)
		clean_textures(graphics->mlx_ptr, graphics->textures);
	if (state == SUCCESS || state > MLX_WINDOW_FAILED)
		mlx_destroy_window(graphics->mlx_ptr, graphics->window->ptr);
	if (state == SUCCESS || state > MLX_IMAGE_FAILED)
		mlx_destroy_image(graphics->mlx_ptr, graphics->frame->image);
	if (state == SUCCESS || state > MLX_INIT_FAILED)
	{
		mlx_destroy_display(graphics->mlx_ptr);
		free(graphics->mlx_ptr);
	}
	return (state);
}
