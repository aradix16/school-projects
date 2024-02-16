/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:16:20 by aradix            #+#    #+#             */
/*   Updated: 2024/02/15 17:45:23 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LCG_MULTIPLIER 1103515245
#define LCG_INCREMENT 12345
#define LCG_MODULUS 0x80000000

unsigned int	ft_rand(unsigned int *seed)
{
	printf("%d\n", *seed);
	*seed = (*seed * LCG_MULTIPLIER + LCG_INCREMENT) % LCG_MODULUS;
	return (*seed);
}
