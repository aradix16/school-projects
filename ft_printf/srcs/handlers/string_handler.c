/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:11:39 by aradix            #+#    #+#             */
/*   Updated: 2024/01/05 14:27:37 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_handler(t_printf *p, char *arg)
{
	if (!arg)
		arg = "(null)";
	store_str_in_buffer(p, arg, ft_strlen(arg));
}
