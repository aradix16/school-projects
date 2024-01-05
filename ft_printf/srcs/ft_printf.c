/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:20:11 by aradix            #+#    #+#             */
/*   Updated: 2024/01/05 14:29:46 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(const char *format, t_printf *p)
{
	p->frmt = (char *)format;
	p->buffer_index = 0;
	p->ret = 0;
	p->base = 0;
}

int	ft_printf(const char *format, ...)
{
	t_printf	p;

	if (!format)
		return (-1);
	va_start(p.ap, format);
	init_struct(format, &p);
	while (*p.frmt)
	{
		if (*p.frmt == '%')
			parsing(&p);
		else
			store_char_in_buffer(&p, *p.frmt++, 1);
	}
	empty_buffer(&p);
	va_end(p.ap);
	return (p.ret);
}
