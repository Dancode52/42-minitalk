/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:56:50 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/15 13:43:47 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line_bonus.h"
#include <stdio.h>

static char	*fill_storage(char *buf, char **store, int fd)
{
	ssize_t	readchars;
	char	*tmp;

	readchars = 1;
	while (readchars > 0)
	{
		readchars = read(fd, buf, BUFFER_SIZE);
		if (readchars == -1 || (readchars == 0
				&& (!*store || (*store)[0] == 0)))
		{
			free(*store);
			*store = NULL;
			return (NULL);
		}
		buf[readchars] = '\0';
		tmp = ft_strjoin(*store, buf);
		if (!tmp)
			return (NULL);
		if (*store)
			free(*store);
		*store = tmp;
		if (ft_strchr(*store, '\n'))
			break ;
	}
	return (*store);
}

static char	*new_line_trunc(char *newline)
{
	ssize_t	i;
	char	*tmp;

	i = 0;
	if (!newline)
		return (NULL);
	while (newline[i] && newline[i] != '\n')
		i++;
	tmp = ft_substr(newline, i + 1, ft_strlen(newline) - (i + 1));
	if (newline[i] == '\n')
		newline[i + 1] = '\0';
	else
		newline[i] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*store[1024];
	char		*buf;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
	{
		if (store[fd])
			free (store[fd]);
		store[fd] = NULL;
		return (NULL);
	}
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	newline = fill_storage(buf, &(store)[fd], fd);
	free(buf);
	if (!newline)
		return (NULL);
	store[fd] = new_line_trunc(newline);
	if (fd <= 2)
	{
		free(store[fd]);
		store[fd] = NULL;
	}
	return (newline);
}
