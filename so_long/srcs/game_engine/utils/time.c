/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:30:15 by aradix            #+#    #+#             */
/*   Updated: 2024/04/12 12:54:26 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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

bool	timeout(const t_nsec t0, const int duration)
{
	t_nsec	current_time;
	int		duration_diff;

	current_time = get_current_time();
	duration_diff = get_diff_ms(current_time, t0);
	return (duration_diff >= duration);
}
