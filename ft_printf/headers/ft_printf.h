/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:39:33 by aradix            #+#    #+#             */
/*   Updated: 2024/01/06 09:25:48 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFFER_SIZE 20

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_printf
{
	char	*frmt;
	va_list	ap;
	int		ret;
	char	buffer[BUFFER_SIZE];
	int		buffer_index;
}			t_printf;

int			ft_printf(const char *format, ...);
/* parsing */
void		parsing(t_printf *p);
/* buffer */
void		store_char_in_buffer(t_printf *p, char c, int n);
void		store_str_in_buffer(t_printf *p, char *s, int n);
void		empty_buffer(t_printf *p);
/* handlers */
void		char_handler(t_printf *p, int arg);
void		string_handler(t_printf *p, char *arg);
void		ptr_handler(t_printf *p, uintmax_t arg);
void		signed_handler(t_printf *p, intmax_t arg, short base, int max);
void		unsigned_handler(t_printf *p, uintmax_t arg, short base, int max);

#endif
