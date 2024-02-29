/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:53:05 by aradix            #+#    #+#             */
/*   Updated: 2024/02/29 10:53:37 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_nsec	get_current_time(void)
{
	t_nsec	current_time;

	clock_gettime(CLOCK_REALTIME, &current_time);
	return (current_time);
}

int	get_diff_ms(t_nsec nano, t_nsec t0)
{
	int	ms;

	ms = (nano.tv_nsec - t0.tv_nsec) / 1000000;
	ms = (nano.tv_sec - t0.tv_sec) * 1000 + ms;
	return (ms);
}
