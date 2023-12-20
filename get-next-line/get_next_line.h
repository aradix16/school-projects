/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:17:05 by aradix            #+#    #+#             */
/*   Updated: 2023/12/20 16:59:00 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_save
{
	int				fd;
	void			*content;
	ssize_t			size;
	struct s_save	*next;
}					t_save;

char				*get_next_line(int fd);
t_save				*ft_get_node(t_save **lst, int fd);
void				ft_remove_node(t_save **lst, int fd);
ssize_t				ft_memchr(const void *s, int c, ssize_t n);
void				*ft_memdup(void *s, ssize_t n);
void				*ft_memcpy(void *dst, void *src, ssize_t n);

#endif
