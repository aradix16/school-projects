/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:31:09 by aradix            #+#    #+#             */
/*   Updated: 2023/12/08 16:02:15 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(unsigned int un)
{
	int	count;

	count = 0;
	if (un == 0)
		return (1);
	while (un != 0)
	{
		un /= 10;
		count++;
	}
	return (count);
}

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	un;
	int				size;

	un = ft_abs(n);
	size = ft_count_digit(un);
	if (n < 0)
		size += 1;
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	s[size] = '\0';
	while (size > 0)
	{
		size--;
		s[size] = (un % 10) + '0';
		un /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
