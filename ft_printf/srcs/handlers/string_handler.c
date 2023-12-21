/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:07:09 by aradix            #+#    #+#             */
/*   Updated: 2023/12/22 00:57:35 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_handler(t_printf *p, char *arg)
{
	int	arg_len;

	if (!arg)
	{
		arg = "(null)";
		if (p->precision > -1 && p->precision < 6 && !(p->flags & MINUS))
			p->precision = 0;
	}
	arg_len = ft_strlen(arg);
	if (p->precision < 0 || p->precision > arg_len)
		p->precision = arg_len;
	p->width -= p->precision;
	if (!(p->flags & MINUS))
		store_char_in_buffer(p, ' ', p->width);
	store_str_in_buffer(p, arg, p->precision);
	if (p->flags & MINUS)
		store_char_in_buffer(p, ' ', p->width);
}
