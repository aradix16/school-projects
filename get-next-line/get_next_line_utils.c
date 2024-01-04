/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:18:17 by aradix            #+#    #+#             */
/*   Updated: 2024/01/04 11:03:06 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, void *src, ssize_t n)
{
	ssize_t	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_memdup(void *s, ssize_t n)
{
	void	*new;

	if (!s)
		return (NULL);
	new = (void *)malloc(sizeof(char) * (n + 1));
	if (!new)
		return (NULL);
	((unsigned char *)new)[n] = '\0';
	return (ft_memcpy(new, s, n));
}

ssize_t	ft_memchr(const void *s, int c, ssize_t n)
{
	ssize_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_remove_node(t_save **lst, int fd)
{
	t_save	*current;
	t_save	*prev;

	current = *lst;
	prev = NULL;
	if (!current)
		return ;
	if (current->fd == fd)
	{
		*lst = current->next;
		free(current->content);
		free(current);
		return ;
	}
	while (current && current->fd != fd)
	{
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		return ;
	prev->next = current->next;
	free(current->content);
	free(current);
}

t_save	*ft_get_node(t_save **lst, int fd)
{
	t_save	**ptr;
	t_save	*new_node;

	ptr = lst;
	while (*ptr && (*ptr)->fd < fd)
		ptr = &(*ptr)->next;
	if (!*ptr || (*ptr)->fd != fd)
	{
		new_node = (t_save *)malloc(sizeof(*new_node));
		if (!new_node)
			return (NULL);
		new_node->fd = fd;
		new_node->next = *ptr;
		new_node->content = NULL;
		new_node->size = 0;
		*ptr = new_node;
	}
	return (*ptr);
}
