/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:23:57 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 19:24:03 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_type(t_printf *p)
{
	if (*p->frmt == 's')
		return (string_handler(p, va_arg(p->ap, char *)));
	// fall in default error handler
}

