/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:43:08 by aradix            #+#    #+#             */
/*   Updated: 2024/03/13 13:59:45 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define SUCCESS 0
# define MALLOC_ERROR 1
# define INVALID_ARG_NUMBER 2
# define INVALID_MAP_EXTENSION 3
# define CANNOT_OPEN_MAP 4
# define READ_ERROR 5
# define INVALID_MAP 6
# define CANNOT_READ_MAP 7
# define UNPLAYABLE_MAP 8
# define MLX_INIT_FAILED 9
# define LOAD_TEXTURES_FAILED 10
# define MLX_WINDOW_FAILED 11
# define MLX_IMAGE_FAILED 12

# define GROUND '0'
# define OBSTACLE '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

# define TILE_SIZE 50

# define N_GROUND 1
# define N_OBSTACLE 1
# define N_PLAYER 3
# define N_COLLECTIBLE 3
/* # define N_EXIT 1 */


# define ANIMATION_DURATION 500

#endif
