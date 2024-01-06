/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:14:46 by aradix            #+#    #+#             */
/*   Updated: 2024/01/06 08:47:36 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(uintmax_t nb, short base)
{
	int	len;

	len = 0;
	if (nb < (uintmax_t)base)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(uintmax_t nb, int len, short base, int max)
{
	static char	s[100];

	s[len] = '\0';
	while (len--)
	{
		if (nb % base < 10)
			s[len] = nb % base + '0';
		else
			s[len] = nb % base + max - 10;
		nb /= base;
	}
	return (s);
}

void	unsigned_handler(t_printf *p, uintmax_t arg, short base, int max)
{
	int	len;

	len = ft_nbrlen(arg, base);
	store_str_in_buffer(p, ft_itoa_base(arg, len, base, max), len);
}
