/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:59 by aradix            #+#    #+#             */
/*   Updated: 2024/01/06 08:02:10 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_type(t_printf *p)
{
	if (*p->frmt == 'c')
		return (char_handler(p, va_arg(p->ap, int)));
	if (*p->frmt == 's')
		return (string_handler(p, va_arg(p->ap, char *)));
	if (*p->frmt == 'p')
		return (ptr_handler(p, (uintmax_t)(va_arg(p->ap, void *))));
	if (*p->frmt == 'd' || *p->frmt == 'i')
		return (signed_handler(p, (intmax_t)(va_arg(p->ap, int)), 10, '9'));
	if (*p->frmt == 'u')
		return (unsigned_handler(
				p, (uintmax_t)(va_arg(p->ap, unsigned int)), 10, '9'));
	if (*p->frmt == 'x')
		return (unsigned_handler(
				p, (uintmax_t)(va_arg(p->ap, unsigned int)), 16, 'a'));
	if (*p->frmt == 'X')
		return (unsigned_handler(
				p, (uintmax_t)(va_arg(p->ap, unsigned int)), 16, 'A'));
	if (*p->frmt == '%')
		return (char_handler(p, '%'));
}

void	parsing(t_printf *p)
{
	p->frmt++;
	if (*p->frmt == '\0')
		return ;
	get_type(p);
	p->frmt++;
}
