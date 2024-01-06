/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:14:46 by aradix            #+#    #+#             */
/*   Updated: 2024/01/06 07:42:25 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_handler(t_printf *p, uintmax_t arg, short base, int max)
{
	int	len;

	len = ft_nbrlen(arg, base);
	store_str_in_buffer(p, ft_itoa_base(arg, len, base, max), len);
}
