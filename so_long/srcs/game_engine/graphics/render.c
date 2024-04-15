
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:33:15 by aradix            #+#    #+#             */
/*   Updated: 2024/04/15 16:28:25 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	render(t_game *game, bool lazy_draw)
{
	get_boundaries(game, game->graphics);
	if (lazy_draw)
		draw_map_lazy(game);
	else
        draw_map(game);
	draw_player(game);
	mlx_put_image_to_window(game->graphics->mlx_ptr,
		game->graphics->window->ptr, game->graphics->frame->image, 0, 0);
}
