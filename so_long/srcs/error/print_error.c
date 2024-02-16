/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:56:16 by aradix            #+#    #+#             */
/*   Updated: 2024/02/10 16:58:23 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(short err)
{
	printf("\n\nerr=%d\n", err);
	ft_puts("Error\n");
	if (err == INVALID_ARG_NUMBER)
		ft_puts("Invalid number of arguments\n");
	return (err);
}
