/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:17:25 by aradix            #+#    #+#             */
/*   Updated: 2024/02/26 16:18:11 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_map_extension(const char *filepath)
{
	size_t	len;

	len = ft_strlen(filepath);
	return (len > 4 && ft_strncmp(filepath + (len - 4), ".ber", 4) == 0);
}
