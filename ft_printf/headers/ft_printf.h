/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:21:07 by aradix            #+#    #+#             */
/*   Updated: 2023/12/21 19:24:08 by aradix           ###   ########.fr       */
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
void		init_struct(t_printf *p, bool first_init);

/* BUFFER */
void		store_in_buffer(t_printf *p, char *s, int n);
void		empty_buffer(t_printf *p);

/* PARSING */
void		parsing(t_printf *p);
void		get_flags(t_printf *p);
void		get_type(t_printf *p);

/* HANDLERS */
void		string_handler(t_printf *p, char *arg);

/* LIBFT TMP */
size_t		ft_strlen(const char *s);

#endif
