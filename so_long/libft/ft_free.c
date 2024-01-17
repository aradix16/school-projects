/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:09:35 by aradix            #+#    #+#             */
/*   Updated: 2024/01/18 21:47:54 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
}

static	void	parsing(char **frmt, va_list ap)
{
	(*frmt)++;
	if (**frmt == '\0')
		return ;
	if (**frmt == 'p')
		free_ptr(va_arg(ap, void *)); 
	(*frmt)++;
}

void	ft_free(const char *format, ...)
{
	char	*frmt;
	va_list	ap;

	if (!format)
		return ;
	va_start(ap, format);
	frmt = (char *)format;
	while (*frmt)
	{
		if (*frmt == '%')
			parsing(&frmt, ap);
		else
			frmt++;
	}
	va_end(ap);
}
