/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:47 by aradix            #+#    #+#             */
/*   Updated: 2024/02/15 15:21:20 by aradix           ###   ########.fr       */
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
	while (--i > 0)
		texture[i].image = NULL;
}

bool	load_textures(t_mlx *mlx, t_texture *texture)
{
	mlx->texture = texture;
	init_textures(texture, NB_TEXTURES);
	if (!get_texture_image(mlx, &texture[GRASS0_ID], GRASS0)
		|| !get_texture_data(&texture[GRASS0_ID]))
		return (false);
	if (!get_texture_image(mlx, &texture[GRASS1_ID], GRASS1)
		|| !get_texture_data(&texture[GRASS1_ID]))
		return (false);
	if (!get_texture_image(mlx, &texture[GRASS2_ID], GRASS2)
		|| !get_texture_data(&texture[GRASS2_ID]))
		return (false);
	if (!get_texture_image(mlx, &texture[GRASS3_ID], GRASS3)
		|| !get_texture_data(&texture[GRASS3_ID]))
		return (false);
	if (!get_texture_image(mlx, &texture[GRASS4_ID], GRASS4)
		|| !get_texture_data(&texture[GRASS4_ID]))
		return (false);
	if (!get_texture_image(mlx, &texture[GRASS5_ID], GRASS5)
		|| !get_texture_data(&texture[GRASS5_ID]))
		return (false);
	if (!get_texture_image(mlx, &texture[OBSTACLE0_ID], OBSTACLE0)
		|| !get_texture_data(&texture[OBSTACLE0_ID]))
		return (false);
	if (!get_texture_image(mlx, &texture[OBSTACLE1_ID], OBSTACLE1)
		|| !get_texture_data(&texture[OBSTACLE1_ID]))
		return (false);
	if (!get_texture_image(mlx, &texture[OBSTACLE2_ID], OBSTACLE2)
		|| !get_texture_data(&texture[OBSTACLE2_ID]))
		return (false);
	if (!get_texture_image(mlx, &texture[FLOWER0_ID], FLOWER0)
		|| !get_texture_data(&texture[FLOWER0_ID]))
		return (false);
	if (!get_texture_image(mlx, &texture[FLOWER0_ID], FLOWER0)
		|| !get_texture_data(&texture[FLOWER0_ID]))
		return (false);
	if (!get_texture_image(mlx, &texture[FLOWER1_ID], FLOWER1)
		|| !get_texture_data(&texture[FLOWER1_ID]))
		return (false);
	if (!get_texture_image(mlx, &texture[FLOWER2_ID], FLOWER2)
		|| !get_texture_data(&texture[FLOWER2_ID]))
		return (false);

	if (!get_texture_image(mlx, &texture[PLAYER0_ID], PLAYER0)
		|| !get_texture_data(&texture[PLAYER0_ID]))
		return (false);
	return (true);
}
