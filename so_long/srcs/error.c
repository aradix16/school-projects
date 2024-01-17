/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:19:32 by aradix            #+#    #+#             */
/*   Updated: 2024/01/18 22:22:36 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(short err_id)
{
	printf("Error\n");
	if (err_id == 1)
		printf("%s\n", ERR_ID_1);
	else if (err_id == 2)
		printf("%s\n", ERR_ID_2);
	else if (err_id == 3)
		printf("%s\n", ERR_ID_3);
	else if (err_id == 4)
		printf("%s\n", ERR_ID_4);
	return (err_id);
}
