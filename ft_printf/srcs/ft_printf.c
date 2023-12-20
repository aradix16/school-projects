/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:20:11 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 18:27:22 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_printf *p, bool first_init)
{
	if (first_init)
	{
		p->buffer_i = 0;
		p->ret = 0;
	}
}

void	empty_buffer(t_printf *p)
{
	write(1, p->buffer, p->buffer_i);
	p->ret += p->buffer_i;
	p->buffer_i = 0;
}

void	stock_str(t_printf *p, char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		p->buffer[p->buffer_i++] = s[i++];
		if (i == p->buffer_i)
			empty_buffer(p);
	}
}

void	parsing(t_printf *p)
{
	p->frmt++;
	if (*p->frmt == '\0')
		return ;
	init_struct(p, false);
}

int	ft_printf(const char *format, ...)
{
	t_printf	p;

	if (!format)
		return (-1);
	init_struct(&p, true);
	p.frmt = (char *)format;
	va_start(p.ap, format);
	while (*p.frmt)
	{
		if (*p.frmt == '%')
			parsing(&p);
		else
			stock_str(&p, &*p.frmt++, 1);
	}
	empty_buffer(&p);
	va_end(p.ap);
	return (p.ret);
}

int	main(void)
{
	int	ret;

	ret = ft_printf("Hello %s!", "World");
	printf("\n\nret: %d\n", ret);
	return (0);
}
