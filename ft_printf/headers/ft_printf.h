/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:21:07 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 18:46:22 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFFER_SIZE 100

# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h> // test only
# include <unistd.h>

typedef struct s_printf
{
	char	*frmt;
	va_list	ap;
	int		ret;
	char	buffer[BUFFER_SIZE];
	int		buffer_i;
}			t_printf;

int			ft_printf(const char *, ...);

#endif
