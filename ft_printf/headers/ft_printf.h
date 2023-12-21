/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:21:07 by aradix            #+#    #+#             */
/*   Updated: 2023/12/22 00:50:36 by aradix           ###   ########.fr       */
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
	short	flags;
	int		width;
	int		precision;
	char	buffer[BUFFER_SIZE];
	int		buffer_i;
}			t_printf;

# define SPACE (1 << 0)
# define MINUS (1 << 1)
# define PLUS (1 << 2)
# define HASH (1 << 3)
# define ZERO (1 << 4)

int			ft_printf(const char *, ...);
void		init_struct(t_printf *p, bool first_init);

/* BUFFER */
void		store_str_in_buffer(t_printf *p, char *s, int n);
void		store_char_in_buffer(t_printf *p, char c, int n);
void		empty_buffer(t_printf *p);

/* PARSING */
void		parsing(t_printf *p);
void		get_flags(t_printf *p);
void		get_width(t_printf *p);
void		get_precision(t_printf *p);
void		get_type(t_printf *p);
void	go_to_next_flags(t_printf *p); // use dedicated file

/* HANDLERS */
void		string_handler(t_printf *p, char *arg);

/* LIBFT TMP */
size_t		ft_strlen(const char *s);
int			ft_strchr(const char *s, const char c);
void		ft_print_bits(unsigned int num, int size);
int			ft_isdigit(int c);
int			ft_atoi(const char *nptr);
#endif
