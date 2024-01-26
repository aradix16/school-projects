/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:16:29 by aradix            #+#    #+#             */
/*   Updated: 2023/12/08 15:54:40 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	total_len;

	if ((dst == NULL || src == NULL) && size == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0 || dst_len > size)
		return (src_len + size);
	dst += dst_len;
	total_len = dst_len;
	while (*src && total_len < (size - 1))
	{
		*dst = *src;
		dst++;
		src++;
		total_len++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
