/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:00:08 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 19:23:53 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	parsing(t_printf *p)
{
	p->frmt++;
	if (*p->frmt == '\0')
		return ;
	init_struct(p, false);
	get_flags(p);
	get_type(p);
	p->frmt++;
}
