/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:19:03 by dlanehar          #+#    #+#             */
/*   Updated: 2025/12/23 14:25:18 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *) s1);
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strrchr(set, s1[end]))
		end--;
	ptr = ft_substr(s1, start, (end - start + 1));
	if (!ptr)
		return (NULL);
	return (ptr);
}
