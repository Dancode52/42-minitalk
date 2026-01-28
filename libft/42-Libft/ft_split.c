/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:54:06 by dlanehar          #+#    #+#             */
/*   Updated: 2025/12/23 14:25:18 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

static void	free_memory(char **badmem)
{
	int	i;

	i = 0;
	while (badmem[i])
	{
		free(badmem[i]);
		i++;
	}
	free(badmem);
	return ;
}

static int	word_length(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	word_count(const char *s, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s != NULL && s[i])
	{
		if (s[i] != c)
		{
			wc++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	array = (char **)ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (s[i] && j < word_count(s, c))
	{
		while (s[i] == c)
			i++;
		array[j] = ft_substr(s, i, word_length(&s[i], c));
		if (array[j] == NULL)
		{
			free_memory(array);
			return (NULL);
		}
		i += word_length(&s[i], c);
		j++;
	}
	return (array);
}
