/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:37:05 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/15 13:43:47 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ptr = (char *)malloc(sizeof(char) * 1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}

// {
// 	unsigned int	i;
// 	unsigned int	size;
// 	char			*ptr;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 	{
// 		ptr = ft_strdup("");
// 		return (ptr);
// 	}
// 	size = len;
// 	if (len > ft_strlen(s) - start)
// 		size = ft_strlen(s) - start;
// 	ptr = malloc(size + 1);
// 	if (ptr == NULL)
// 		return (NULL);
// 	while (i < size)
// 	{
// 		ptr[i] = s[start + i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }
