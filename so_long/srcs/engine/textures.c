/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:47 by aradix            #+#    #+#             */
/*   Updated: 2024/02/01 15:44:29 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	get_texture_data(t_texture *texture)
{
	texture->data = mlx_get_data_addr(texture->image, &texture->bits_per_pixel,
			&texture->size_line, &texture->endian);
	return (texture->data);
}

bool	get_texture_image(t_mlx *mlx, t_texture *texture, char *texture_path)
{
	texture->image = mlx_xpm_file_to_image(mlx->ptr, texture_path,
			&texture->width, &texture->height);
	return (texture->image);
}

void	init_textures(t_texture *texture, int i)
{
	while (--i >= 0)
		texture[i].image = NULL;
}

bool	load_textures(t_mlx *mlx, t_texture *texture)
{
	mlx->texture = texture;
	init_textures(texture, NB_TEXTURES);
	if (!get_texture_image(mlx, &texture[0], "empty.xpm")
		|| !get_texture_data(&texture[0]))
		return (false);
	if (!get_texture_image(mlx, &texture[1], "wall.xpm")
		|| !get_texture_data(&texture[1]))
		return (false);
	if (!get_texture_image(mlx, &texture[2], "player.xpm")
		|| !get_texture_data(&texture[2]))
		return (false);
	if (!get_texture_image(mlx, &texture[3], "collectible.xpm")
		|| !get_texture_data(&texture[3]))
		return (false);
	if (!get_texture_image(mlx, &texture[4], "exit.xpm")
		|| !get_texture_data(&texture[4]))
		return (false);
	return (true);
}
