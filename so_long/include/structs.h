/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:37:47 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 22:40:30 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_textures
{
}				t_textures;

typedef struct s_image
{
	void		*ptr;
	char		*data;
}				t_image;

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
	t_image		*image;
	t_textures	*textures;
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
