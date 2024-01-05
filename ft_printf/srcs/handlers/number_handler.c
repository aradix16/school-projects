/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:14:46 by aradix            #+#    #+#             */
/*   Updated: 2024/01/05 15:44:12 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(ssize_t nb, short base)
{
	int	len;

	len = 0;
	if (nb < base)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(ssize_t nb, short base)
{
	static char	s[101];
	int			len;

	len = ft_nbrlen(nb, base);
	s[len] = '\0';
	while (len--)
	{
		if (nb % base < 10)
			s[len] = nb % base + '0';
		/* else */
		/* 	s[len] = nb % base + max - 10; */ // usefile with base > 10 like hex
		nb /= base;
	}
	return (s);
}

ssize_t	ft_abs(ssize_t nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

void	number_handler(t_printf *p, ssize_t arg)
{
	char	*s;

	if (arg < 0)
	{
		arg *= -1;
		store_char_in_buffer(p, '-', 1);
	}
	s = ft_itoa_base(arg, p->base);
	store_str_in_buffer(p, s, ft_strlen(s));
}
