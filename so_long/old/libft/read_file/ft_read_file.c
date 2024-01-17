/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:10:23 by aradix            #+#    #+#             */
/*   Updated: 2024/01/17 20:24:34 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_content(int fd, ssize_t size)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	read_ret;
	char	*content;

	read_ret = read(fd, buffer, BUFFER_SIZE);
	if (read_ret == -1)
		return (NULL);
	if (read_ret == 0)
	{
		content = ((char *)malloc(sizeof(char) * (size + 1)));
		if (content)
			content[size] = '\0';
		return (content);
	}
	content = get_content(fd, size + read_ret);
	if (!content)
		return (NULL);
	ft_memncpy(content + size, buffer, read_ret);
	return (content);
}

char	*ft_read_file(const char *filename)
{
	int		fd;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = get_content(fd, 0);
	close(fd);
	return (content);
}
