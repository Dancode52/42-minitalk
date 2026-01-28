/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:11:33 by dlanehar          #+#    #+#             */
/*   Updated: 2025/12/23 14:25:18 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lensrc;
	size_t	lendst;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	i = lendst;
	j = 0;
	if (size == 0 || lendst > size)
		return (lensrc + size);
	if (!*src)
		return (lendst);
	while (src[j] && lendst + j < size - 1)
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (lensrc + lendst);
}
