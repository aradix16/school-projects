/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:50:02 by aradix            #+#    #+#             */
/*   Updated: 2024/01/05 17:15:04 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_handler(t_printf *p,   uintmax_t arg)
{
	char *s;

	store_str_in_buffer(p, "0x", 2);
	s = ft_itoa_base(arg, p->base, 'a');
	store_str_in_buffer(p, s, ft_strlen(s));
}
