/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:23:16 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 20:33:15 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(t_printf *p)
{
	short	tmp;

	while (1)
	{
		tmp = ft_strchr(" -+#0", *p->frmt);
		if (tmp == -1)
			break ;
		p->flags |= (1 << tmp);
		p->frmt++;
	}
	/* get_width_pr(p); */
	/* if (p->flags & ZERO && p->flags & MINUS) */
	/* 	p->flags &= ~ZERO; */
	/* if (p->flags & PLUS && p->flags & SPACE) */
	/* 	p->flags &= ~SPACE; */
	/* if (p->min_len < 0) */
	/* { */
	/* 	p->min_len *= -1; */
	/* 	p->flags |= MINUS; */
	/* } */
	/**/
}
