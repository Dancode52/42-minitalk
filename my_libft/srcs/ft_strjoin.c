/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:34:03 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/15 13:43:47 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	if (s1)
		i = ft_strlen(s1);
	j = 0;
	if (s2)
		j = ft_strlen(s2);
	str = ft_calloc(sizeof(char), i + j + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j);
	return (str);
}
