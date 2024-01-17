/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:29:49 by aradix            #+#    #+#             */
/*   Updated: 2024/01/17 19:36:40 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_clean_exit(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

static int	ft_split_len(char const *s, char c)
{
	const char	*start;

	start = s;
	while (*s && *s != c)
		s++;
	return (s - start);
}

static int	ft_split_counter(char const *s, char c, int count)
{
	while (*s && *s == c)
		s++;
	if (*s == '\0')
		return (count);
	while (*s && *s != c)
		s++;
	return (ft_split_counter(s, c, count + 1));
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		split_len;
	int		i;

	printf("ici");
	split = (char **)malloc(sizeof(char *) * (ft_split_counter(s, c, 0) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			split_len = ft_split_len(s, c);
			split[i] = (char *)malloc(sizeof(char) * (split_len + 1));
			if (split[i] == NULL)
				return (ft_clean_exit(split, i - 1));
			ft_strlcpy(split[i], s, split_len + 1);
			s += split_len;
			i++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}
