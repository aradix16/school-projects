/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:56:00 by aradix            #+#    #+#             */
/*   Updated: 2024/02/08 19:17:11 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_extension(const char *filepath)
{
	size_t	len;

	len = ft_strlen(filepath);
	return (len > 4 && ft_strncmp(filepath + (len - 4), ".ber", 4) == 0);
}
