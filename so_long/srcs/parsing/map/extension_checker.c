/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:08 by aradix            #+#    #+#             */
/*   Updated: 2024/01/30 15:19:15 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	extension_checker(const char *filepath)
{
	size_t	len;

	len = ft_strlen(filepath, '\0');
	return (len > 4 && ft_strncmp(filepath + (len - 4), ".ber", 4) == 0);
}
