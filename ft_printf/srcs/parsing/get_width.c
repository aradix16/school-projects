/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:33:19 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 21:40:53 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width(t_printf *p)
{
	if (ft_isdigit(*p->frmt) || *p->frmt == '*')
	{
		if (*p->frmt == '*')
			p->width = va_arg(p->ap, int);
		else
			p->width = ft_atoi(*&p->frmt);
		go_to_next_flags(p);
	}
	if (p->width < 0)
	{
		p->flags |= MINUS;
		p->width *= -1;
	}
}
