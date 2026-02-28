/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:28:05 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/15 13:43:47 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	written_chars;

	written_chars = 0;
	if (!s || fd < 0)
		return (-1);
	written_chars += ft_putstr_fd(s, fd);
	written_chars += ft_putchar_fd('\n', fd);
	return (written_chars);
}
