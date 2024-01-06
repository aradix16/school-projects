/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:50:02 by aradix            #+#    #+#             */
/*   Updated: 2024/01/06 07:35:41 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_handler(t_printf *p, uintmax_t arg)
{
	store_str_in_buffer(p, "0x", 2);
	unsigned_handler(p, arg, 16, 'a');
}
