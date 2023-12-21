/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:20:11 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 18:46:14 by aradix           ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	const char	*start = s;

	while (*s)
		s++;
	return (s - start);
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
		if (p->buffer_i == BUFFER_SIZE)
			empty_buffer(p);
	}
}

void	string_handler(t_printf *p, char *arg)
{
	stock_str(p, arg, ft_strlen(arg));
}

void	get_type(t_printf *p)
{
	if (*p->frmt == 's')
		return (string_handler(p, va_arg(p->ap, char *)));
	// fall in default error handler
}

void	parsing(t_printf *p)
{
	p->frmt++;
	if (*p->frmt == '\0')
		return ;
	init_struct(p, false);
	get_type(p);
	p->frmt++;
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

	ret = ft_printf("Hello %s !", "World");
	printf("\n\nret: %d\n", ret);
	return (0);
}
