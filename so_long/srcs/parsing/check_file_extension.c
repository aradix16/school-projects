/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:22:58 by aradix            #+#    #+#             */
/*   Updated: 2024/01/24 19:23:26 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_file_extension_valid(char *filepath)
{
	size_t	len;

	len = ft_strlen(filepath, '\0');
	return (len > 4 && ft_strncmp(filepath + (len - 4), ".ber", 4) == 0);
}
