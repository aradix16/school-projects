/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:14:46 by aradix            #+#    #+#             */
/*   Updated: 2024/01/06 08:45:59 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_handler(t_printf *p, intmax_t arg, short base, int max)
{
	if (arg < 0)
	{
		store_char_in_buffer(p, '-', 1);
		return (unsigned_handler(p, (uintmax_t)(arg * -1), base, max));
	}
	return (unsigned_handler(p, arg, base, max));
}
