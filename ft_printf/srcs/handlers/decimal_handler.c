/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:11:18 by aradix            #+#    #+#             */
/*   Updated: 2023/12/22 16:41:23 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	decimal_handler(t_printf *p, int arg)
{
	int	arg_len;

	arg_len = ft_nbrlen(arg, 10);
	if (p->precision <= arg_len)
		p->precision = 0;
	p->width -= p->precision;
	store_char_in_buffer(p,  ' ', p->width);
	p->precision -= arg_len;
	store_char_in_buffer(p, '0', p->precision);
	store_char_in_buffer(p, arg - '0', arg_len);
}
	

	


	/* -42 avec precision de 4  */
	/* -0042  */
	/**/
	/* 42 avec precison de 4  */
	/* 0042  */
	



	/* int		min; */
	/* int		prec; */
	/**/
	/* if (p->precision == -1 && nb == 0) */
	/* 	len = 0; */
	/* prec = check_zero(p, len); */
	/* min = p->min_len ? (p->min_len - prec - len) : 0; */
	/* if ((p->flags & PLUS) || (p->flags & SPACE) || p->neg) */
	/* 	min -= 1; */
	/* if (p->flags & MINUS) */
	/* { */
	/* 	padding(p, prec, len, nb); */
	/* 	if (min > 0) */
	/* 		n_buffer(p, ' ', min); */
	/* } */
	/* else */
	/* { */
	/* 	if (min > 0) */
	/* 		n_buffer(p, ' ', min); */
	/* 	padding(p, prec, len, nb); */
	/* } */
	/**/
