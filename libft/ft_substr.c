/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:50:02 by aradix            #+#    #+#             */
/*   Updated: 2023/12/08 16:00:13 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	tmp;
	char	*sub;

	if (len == 0)
		return (ft_calloc(1, sizeof(char)));
	tmp = ft_strlen(s);
	if (start > tmp)
		return (ft_calloc(1, sizeof(char)));
	if ((start + len) > tmp)
		len = (tmp - start);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
