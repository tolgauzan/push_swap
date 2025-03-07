/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 05:19:38 by tuzan             #+#    #+#             */
/*   Updated: 2025/03/05 05:19:38 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = -1;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			split[++i] = (char *)malloc((word_len(s, c) + 1) * sizeof(char));
			if (!split[i])
				return (free_split(split));
			j = 0;
			while (*s && *s != c)
				split[i][j++] = *s++;
			split[i][j] = '\0';
		}
	}
	split[++i] = NULL;
	return (split);
}
