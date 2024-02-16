/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:47 by aradix            #+#    #+#             */
/*   Updated: 2024/02/10 20:55:36 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

short	get_map_width(t_map *map, int fd)
{
	char	c;
	short	read_ret;

	while (1)
	{
		read_ret = read(fd, &c, 1);
		if (read_ret == -1)
			return (READ_ERROR);
		if (read_ret == 0)
			return (INVALID_MAP_CONTENT);
		if (c == '\n')
			return (SUCCESS);
		if (c != '1')
			return (INVALID_MAP_CONTENT);
		++map->width;
	}
}

short	get_line(int fd, char **line, unsigned int width)
{
	ssize_t	read_ret;

	*line = malloc(sizeof(char) * (width + 1));
	if (!(*line))
		return (MALLOC_ERROR);
	read_ret = read(fd, *line, width + 1);
	if (read_ret == -1)
		return (CANNOT_READ_MAP);
	if (read_ret == 0)
	{
		free(*line);
		*line = NULL;
		return (SUCCESS);
	}
	else
		(*line)[width] = '\0';
	return (SUCCESS);
}

short	file_to_lst(t_map *map, int fd, t_list **head_ptr, char *line)
{
	short	err;
	t_list	*node;
	t_list	*last_node;

	last_node = NULL;
	if (!line)
		return (MALLOC_ERROR);
	while (line)
	{
		node = ft_lstnew(line);
		if (!node)
			return (free(line), MALLOC_ERROR);
		if (!*head_ptr)
			*head_ptr = node;
		else
			last_node->next = node;
		last_node = node;
		err = get_line(fd, &line, map->width);
		if (err)
			return (MALLOC_ERROR);
		++map->height;
	}
	return (SUCCESS);
}

short	lst_to_array(t_map *map, t_list *head)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	map->content = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->content)
		return (MALLOC_ERROR);
	map->content[map->height] = NULL;
	while (head)
	{
		map->content[i] = head->content;
		tmp = head;
		head = head->next;
		free(tmp);
		++i;
	}
	return (SUCCESS);
}

short	read_and_store_map(t_map *map, int fd)
{
	short	err;
	t_list	*head;

	if (fd < 0)
		return (CANNOT_OPEN_MAP);
	err = get_map_width(map, fd);
	if (err)
		return (err);
	head = NULL;
	err = file_to_lst(map, fd, &head, ft_strnew(map->width, '1'));
	if (err)
		return (ft_lstfree(head), err);
	err = lst_to_array(map, head);
	if (err)
		return (ft_lstfree(head), err);
	return (SUCCESS);
}
