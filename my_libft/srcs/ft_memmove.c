/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:26:28 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/15 13:43:47 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*csrc;
	char		*cdest;

	i = n;
	csrc = (const char *)src;
	cdest = (char *)dest;
	if (src < dest)
	{
		while (i > 0)
		{
			cdest[i - 1] = csrc[i - 1];
			i--;
		}
		return (cdest);
	}
	cdest = ft_memcpy(dest, src, n);
	return (cdest);
}
