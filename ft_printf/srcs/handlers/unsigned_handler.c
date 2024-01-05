/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:14:46 by aradix            #+#    #+#             */
/*   Updated: 2024/01/05 17:14:03 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_handler(t_printf *p, uintmax_t arg)
{
	char	*s;

	s = ft_itoa_base(arg, p->base, 10);
	store_str_in_buffer(p, s, ft_strlen(s));
}
