/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:58:53 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 19:11:30 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	empty_buffer(t_printf *p)
{
	write(1, p->buffer, p->buffer_i);
	p->ret += p->buffer_i;
	p->buffer_i = 0;
}

void	store_in_buffer(t_printf *p, char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		p->buffer[p->buffer_i++] = s[i++];
		if (p->buffer_i == BUFFER_SIZE)
			empty_buffer(p);
	}
}
