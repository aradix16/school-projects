/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:58:53 by aradix            #+#    #+#             */
/*   Updated: 2024/01/06 08:25:18 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	empty_buffer(t_printf *p)
{
	write(1, p->buffer, p->buffer_index);
	p->ret += p->buffer_index;
	p->buffer_index = 0;
}

void	store_str_in_buffer(t_printf *p, char *s, int n)
{
	int	i;

	i = 0;
	while (i < n && s[i])
	{
		p->buffer[p->buffer_index++] = s[i++];
		if (p->buffer_index == BUFFER_SIZE)
			empty_buffer(p);
	}
}

void	store_char_in_buffer(t_printf *p, char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		p->buffer[p->buffer_index++] = c;
		i++;
		if (p->buffer_index == BUFFER_SIZE)
			empty_buffer(p);
	}
}
