/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:07:09 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 19:15:04 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_handler(t_printf *p, char *arg)
{
	store_in_buffer(p, arg, ft_strlen(arg));
}
