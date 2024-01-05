/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:39:33 by aradix            #+#    #+#             */
/*   Updated: 2024/01/05 15:44:25 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFFER_SIZE 1

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
	int		buffer_index;
	short	base;
}			t_printf;

/* test only */
size_t		ft_strlen(const char *s);

int			ft_printf(const char *, ...);

/* parsing */
void		parsing(t_printf *p);

/* buffer */
void		store_char_in_buffer(t_printf *p, char c, int n);
void		store_str_in_buffer(t_printf *p, char *s, int n);
void		empty_buffer(t_printf *p);

/* handlers */
void		number_handler(t_printf *p, ssize_t arg);
void		string_handler(t_printf *p, char *arg);

#endif
