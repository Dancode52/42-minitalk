/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 12:32:39 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/15 13:43:47 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

ssize_t	ft_putuint_base_fd(size_t n, char *base, int fd)
{
	size_t	len;
	ssize_t	i;

	if (!base)
		return (-1);
	i = 0;
	len = ft_strlen(base);
	if (n >= len)
	{
		i += ft_putuint_base_fd(n / len, base, fd);
		i += ft_putuint_base_fd(n % len, base, fd);
	}
	else
		i += ft_putchar_fd(base[n], fd);
	return (i);
}
