/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:10:31 by aradix            #+#    #+#             */
/*   Updated: 2024/03/14 15:16:58 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(short err)
{
	ft_puts("Error\n");
	if (err == INVALID_ARG_NUMBER)
		ft_puts("todo\n");
	else if (err == INVALID_MAP_EXTENSION)
		ft_puts("todo\n");
	else if (err == CANNOT_OPEN_MAP)
		ft_puts("todo\n");
	else if (err == READ_ERROR)
		ft_puts("todo\n");
	else if (err == INVALID_MAP)
		ft_puts("todo\n");
	else if (err == CANNOT_READ_MAP)
		ft_puts("todo\n");
	printf("%d\n", err);
	return (err);
}
