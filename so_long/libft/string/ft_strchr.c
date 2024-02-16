/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:55:35 by aradix            #+#    #+#             */
/*   Updated: 2024/02/06 18:26:53 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strchr(const char *s, int c)
{
	const char	*start;

	start = s;
	if ((unsigned char)c == '\0')
		return (ft_strlen(s));
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (s - start);
		s++;
	}
	return (-1);
}
