/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:59 by aradix            #+#    #+#             */
/*   Updated: 2024/01/05 15:45:19 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_type(t_printf *p)
{
	if (*p->frmt == 'd')
		p->base = 10;
	else if (*p->frmt == 'b')
		p->base = 2;
	else if (*p->frmt == 's')
		return (string_handler(p, va_arg(p->ap, char *)));
	if (p->base > 0)
		return (number_handler(p, va_arg(p->ap, ssize_t)));
}

void	parsing(t_printf *p)
{
	p->frmt++;
	if (*p->frmt == '\0')
		return ;
	get_type(p);
	p->frmt++;
}
