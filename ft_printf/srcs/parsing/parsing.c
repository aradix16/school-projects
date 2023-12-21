/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:00:08 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 21:49:07 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	go_to_next_flags(t_printf *p)
{
	if (*p->frmt == '*')
		p->frmt++;
	else if (ft_isdigit(*p->frmt))
		while (p->frmt && ft_isdigit(*p->frmt))
			p->frmt++;
}

void	parsing(t_printf *p)
{
	p->frmt++;
	if (*p->frmt == '\0')
		return ;
	init_struct(p, false);
	get_flags(p);
	get_width(p);
	get_precision(p);
	get_type(p);
	p->frmt++;
}
