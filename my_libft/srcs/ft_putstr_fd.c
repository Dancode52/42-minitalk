/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:23:19 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/15 13:43:47 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

ssize_t	ft_putstr_fd(char *s, int fd)
{
	ssize_t	written_chars;

	written_chars = 0;
	if (!s || fd < 0)
		return (-1);
	written_chars = write(fd, s, ft_strlen(s));
	return (written_chars);
}
