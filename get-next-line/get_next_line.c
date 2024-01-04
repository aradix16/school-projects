/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:16:47 by aradix            #+#    #+#             */
/*   Updated: 2024/01/04 11:02:31 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*allocate_line(t_save *p, void *buffer, ssize_t line_size, ssize_t eol)
{
	void	*line;

	line = (void *)malloc(sizeof(char) * (line_size + eol + 1));
	if (!line)
		return (NULL);
	((unsigned char *)line)[line_size + eol] = '\0';
	ft_memcpy(line + line_size, buffer, eol);
	if (p->content)
	{
		ft_memcpy(line, p->content, p->size);
		free(p->content);
		p->content = NULL;
		p->size = 0;
	}
	return (line);
}

void	*init_line(t_save *p, void *buffer, ssize_t line_size, ssize_t read_ret)
{
	ssize_t	eol;
	char	*line;

	eol = 0;
	if (read_ret > 0)
		eol = ft_memchr(buffer, '\n', read_ret) + 1;
	line = allocate_line(p, buffer, line_size, eol);
	if (!line)
		return (free(buffer), NULL);
	if (read_ret > eol)
	{
		p->content = ft_memdup(buffer + eol, (read_ret - eol));
		if (!p->content)
			return (free(buffer), free(line), NULL);
		p->size = read_ret - eol;
	}
	free(buffer);
	return (line);
}

void	*read_next_line(int fd, t_save *p, ssize_t line_size)
{
	void	*buffer;
	ssize_t	read_ret;
	void	*line;

	buffer = (void *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read_ret = read(fd, buffer, BUFFER_SIZE);
	if (read_ret == -1 || (read_ret == 0 && line_size == 0 && p->size == 0))
		return (free(buffer), NULL);
	if (read_ret == 0 || ft_memchr(buffer, '\n', read_ret) > -1)
		return (init_line(p, buffer, line_size, read_ret));
	line = read_next_line(fd, p, line_size + read_ret);
	if (!line)
		return (free(buffer), NULL);
	ft_memcpy(line + line_size, buffer, read_ret);
	return (free(buffer), line);
}

void	*get_stored_line(t_save *p, ssize_t line_size)
{
	void	*line;
	void	*tmp;

	line_size++;
	line = ft_memdup(p->content, line_size);
	if (!line)
		return (NULL);
	if (p->size > line_size)
	{
		tmp = ft_memdup(p->content + line_size, (p->size - line_size));
		if (!tmp)
			return (free(line), NULL);
		p->size -= line_size;
		free(p->content);
		p->content = tmp;
	}
	else
	{
		p->size = 0;
		free(p->content);
		p->content = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_save	*head;
	t_save			*p;
	void			*line;
	ssize_t			line_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	p = ft_get_node(&head, fd);
	if (!p)
		return (NULL);
	line_size = ft_memchr(p->content, '\n', p->size);
	if (line_size > -1)
		line = get_stored_line(p, line_size);
	else
	{
		line_size = p->size;
		line = read_next_line(fd, p, line_size);
	}
	if (!line)
		ft_remove_node(&head, fd);
	return (line);
}
