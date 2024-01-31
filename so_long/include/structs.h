/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:37:47 by aradix            #+#    #+#             */
/*   Updated: 2024/01/31 17:37:35 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_texture
{
	void		*image;
	char		*data;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_texture;

typedef struct s_frame
{
	void		*image;
	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_frame;

typedef struct s_window
{
	void		*ptr;
	int			width;
	int			height;
}				t_window;

typedef struct s_mlx
{
	void		*ptr;
	t_window	*window;
	t_frame		*frame;
	t_texture	*texture;
}				t_mlx;

typedef struct s_state
{
	size_t		exit_position;
	size_t		player_position;
	size_t		collectibles_count;
}				t_state;

typedef struct s_map
{
	char		*ptr;
	size_t		cols;
	size_t		rows;
}				t_map;

typedef struct s_game
{
	t_map		*map;
	t_state		*state;
	t_mlx		*mlx;
}				t_game;

#endif
