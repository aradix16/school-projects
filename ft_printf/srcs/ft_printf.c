/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:20:11 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 19:21:20 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* - tmp - */
size_t	ft_strlen(const char *s)
{
	const char	*start = s;

	while (*s)
		s++;
	return (s - start);
}
/* ------- */

void	init_struct(t_printf *p, bool first_init)
{
	if (first_init)
	{
		p->buffer_i = 0;
		p->ret = 0;
	}
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
			store_in_buffer(&p, &*p.frmt++, 1);
	}
	empty_buffer(&p);
	va_end(p.ap);
	return (p.ret);
}

int	main(void)
{
	int	ret;

	ret = ft_printf("Hello %-5s !", "World");
	printf("\n\nret: %d\n", ret);
	return (0);
}
