/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:14:46 by aradix            #+#    #+#             */
/*   Updated: 2024/01/05 17:26:02 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_handler(t_printf *p, intmax_t arg)
{
	char	*s;

	if (arg < 0)
	{
		store_char_in_buffer(p, '-', 1);
		return (unsigned_handler(p, (uintmax_t)(arg * -1)));
	}
	s = ft_itoa_base(arg, p->base, 10);
	store_str_in_buffer(p, s, ft_strlen(s));
}
