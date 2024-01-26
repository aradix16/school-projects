/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:33:28 by aradix            #+#    #+#             */
/*   Updated: 2024/01/25 21:38:21 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *src, size_t n)
{
	void	*new;

	new = (void *)malloc(sizeof(char) * n);
	if (!new)
		return (NULL);
	return (ft_memncpy(new, src, n));
}
