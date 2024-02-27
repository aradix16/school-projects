/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:41:36 by aradix            #+#    #+#             */
/*   Updated: 2024/02/26 12:50:15 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* STRING */
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
ssize_t				ft_strchr(const char *s, int c);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strnew(size_t n, int c);
void				ft_mtrxfree(char **mtrx);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/* STDIO */
ssize_t				ft_puts(const char *s);

/* LIST */
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstfree(t_list *lst);

/* STDLIB */
int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);
unsigned int		ft_rand(unsigned int *seed);

/* MATH */
int					ft_min(int a, int b);
int					ft_max(int a, int b);

#endif
