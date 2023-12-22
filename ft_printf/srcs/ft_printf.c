/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:20:11 by aradix            #+#    #+#             */
/*   Updated: 2023/12/22 16:48:47 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* - tmp - */
void	ft_print_bits(unsigned int num, int size)
{
	for (int bit = 0; bit < (size * 8); bit++)
	{
		printf("%i ", num & 0x01);
		num = num >> 1;
	}
}

size_t	ft_strlen(const char *s)
{
	const char	*start = s;

	while (*s)
		s++;
	return (s - start);
}

int	ft_strchr(const char *s, const char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_isdigit(int c)
{
	return ((c > 47) && (c < 58));
}

int	ft_atoi(const char *nptr)
{
	long	n;
	short	sign;

	sign = 1;
	n = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
		n = ((n * 10) + (*nptr++ - '0'));
	return (sign * n);
}

int	ft_nbrlen(int nb, int base)
{
	int  len;

	len = 0;
	if (nb < 0)
		nb *= -1;
	if (nb < base)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb, int base)
char	*c_itoa(t_printf *p, uintmax_t nb, size_t len, char c)

{
	static char	s[101];

	s[len] = '\0';
	while (len--)
	{
		s[len] = (nb % p->base < 10) ? nb % p->base + '0'
		: nb % p->base + c - 10;
		nb /= p->base;
	}
	return (s);
}
/* ------- */

void	init_struct(t_printf *p, bool first_init)
{
	if (first_init)
	{
		p->buffer_i = 0;
		p->ret = 0;
	}
	p->flags = 0;
	p->width = 0;
	p->precision = -1;
}

int	ft_printf(const char *format, ...)
{
	t_printf	p;

	if (!format)
		return (-1);
	init_struct(&p, true);
	p.frmt = (char *)format;
	va_start(p.ap, format);
	while (*p.frmt)
	{
		if (*p.frmt == '%')
			parsing(&p);
		else
			store_char_in_buffer(&p, *p.frmt++, 1);
	}
	empty_buffer(&p);
	va_end(p.ap);
	return (p.ret);
}

int	main(void)
{
	int		ret;
	char	*s;


	/* %d */
	ft_printf(">%d<", 42);

	/*	%s */
	s = NULL;
	ret = ft_printf("1:H");
	printf("%d\n", ret);
	ret = ft_printf("2:Hello %s!", "World");
	printf("%d\n", ret);
	ret = ft_printf("3:Hello %s!", s);
	printf("%d\n", ret);
	ret = ft_printf("4:Hello %1s!", s);
	printf("%d\n", ret);
	ret = ft_printf("5:Hello %9s!", s);
	printf("%d\n", ret);
	ret = ft_printf("6:Hello %*s!", -9, "W");
	printf("%d\n", ret);
	ret = ft_printf("7:Hello %*.4s!", 20, "World");
	printf("%d\n", ret);
	ret = ft_printf("8:Hello %.*s!", 1, "World");
	printf("%d\n", ret);
	ret = ft_printf("9:Hello %.*s!", -1, "World");
	printf("%d\n", ret);
	printf("\n\n\n");

	ret = printf("1:H");
	printf("%d\n", ret);
	ret = printf("2:Hello %s!", "World");
	printf("%d\n", ret);
	ret = printf("3:Hello %s!", s);
	printf("%d\n", ret);
	ret = printf("4:Hello %1s!", s);
	printf("%d\n", ret);
	ret = printf("5:Hello %9s!", s);
	printf("%d\n", ret);
	ret = printf("6:Hello %*s!", -9, "W");
	printf("%d\n", ret);
	ret = printf("7:Hello %*.4s!", 20, "World");
	printf("%d\n", ret);
	ret = printf("8:Hello %.*s!", 1, "World");
	printf("%d\n", ret);
	ret = printf("9:Hello %.*s!", -1, "World");
	printf("%d\n", ret);
	return (0);
}
