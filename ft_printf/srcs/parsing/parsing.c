/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:59 by aradix            #+#    #+#             */
/*   Updated: 2024/01/05 17:39:57 by aradix           ###   ########.fr       */
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
	{
		p->base = 16;
		return (ptr_handler(p, (uintmax_t)(va_arg(p->ap, void *))));
	}
	if (*p->frmt == 'd' || *p->frmt == 'i')
	{
		p->base = 10;
		return (signed_handler(p, (intmax_t)(va_arg(p->ap, int))));
	}
	if (*p->frmt == 'u')
	{
		p->base = 10;
		return (signed_handler(p, (uintmax_t)(va_arg(p->ap, unsigned int))));
	}
	if (*p->frmt == 'x')
	{
		p->base = 16;
		return (unsigned_handler(p, (uintmax_t)(va_arg(p->ap, unsigned int))));
		// single function that get the base as param and the max letter . 
		//
	}


	/* if (*p->frmt == '%') */
	/* 	return (char_handler(p, '%')); */
	/* else if (*p->frmt == 'b') */
	/* 	p->base = 2; */
	/* if (p->base > 0) */
	/* 	return (number_handler(p, va_arg(p->ap, long))); */
}

void	parsing(t_printf *p)
{
	p->frmt++;
	if (*p->frmt == '\0')
		return ;
	get_type(p);
	p->frmt++;
}
