/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:36:18 by aradix            #+#    #+#             */
/*   Updated: 2023/12/22 00:44:32 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_precision(t_printf *p)
{
	if (*p->frmt != '.')
		return ;
	p->frmt++;
	while (p->frmt && *p->frmt == '0')
		p->frmt++;
	if (*p->frmt == '*')
		p->precision = va_arg(p->ap, int);
	else
		p->precision = ft_atoi(*&p->frmt);
	// if precision < 0 disable precision 
	go_to_next_flags(p);
}
