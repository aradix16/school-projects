/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:49:12 by aradix            #+#    #+#             */
/*   Updated: 2024/03/06 15:40:23 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct timespec	t_nsec;

/* typedef struct s_render */
/* { */
/* 	bool				key_press; */
/* 	int					animation_state; */
/* 	t_coordinate		move; */
/* 	t_nsec				t0; */
/* }						t_render; */

typedef struct s_coordinate
{
	int					x;
	int					y;
}						t_coordinate;

typedef struct s_mlx_img
{
	void				*image;
	int					*data;
	t_coordinate		size;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_mlx_img;

typedef struct s_window
{
	void				*ptr;
	t_coordinate		size;
}						t_window;

typedef struct s_textures
{
	t_mlx_img			ground[N_GROUND];
	t_mlx_img			obstacle[N_OBSTACLE];
	t_mlx_img			player[N_PLAYER];
	t_mlx_img			collectible[N_COLLECTIBLE];
	int					n;
}						t_textures;

typedef struct s_graphics
{
	void				*mlx_ptr;
	t_textures			*textures;
	t_window			*window;
	t_mlx_img			*frame;
}						t_graphics;

typedef struct s_player
{
	t_coordinate		pos;
	int					n_moves;
}						t_player;

typedef struct s_map
{
	char				**content;
	t_coordinate		size;
}						t_map;

typedef struct s_game
{
	t_map				*map;
	t_player			*player;
	bool				exit;
	int					n_collectibles;
	t_graphics			*graphics;
}						t_game;

#endif
