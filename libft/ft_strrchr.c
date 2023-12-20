/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:31:56 by aradix            #+#    #+#             */
/*   Updated: 2023/12/08 15:56:26 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	tmp = 0;
	if ((unsigned char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*(s + i))
	{
		if (*(s + i) == (unsigned char)c)
			tmp = i;
		i++;
	}
	if (tmp == 0 && *(s + tmp) != (unsigned char)c)
		return (NULL);
	return ((char *)s + tmp);
}
