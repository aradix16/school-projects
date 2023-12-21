/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:23:16 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 20:09:36 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchr(const char *s, const char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

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
	/* while ((tmp = s_chr("lh", *p->frmt)) > -1 && *p->frmt++) */
	/* { */
	/* 	if (tmp == 1 && p->flags & H) */
	/* 		p->flags |= HH; */
	/* 	else */
	/* 		p->flags |= (1 << (tmp + 5)); */
	/* } */
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
