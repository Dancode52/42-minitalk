/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:26:04 by dlanehar          #+#    #+#             */
/*   Updated: 2025/12/23 09:22:36 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...)__attribute__((format(printf, 1, 2)));
ssize_t	ft_usiputnbrcount_base_fd(size_t n, char *base, int fd);
ssize_t	ft_putstrcount_fd(char *s, int fd);
ssize_t	ft_putcharcount_fd(char c, int fd);
ssize_t	ft_putnbrcount_fd(int n, int fd);
size_t	ft_strlen(const char *s);

#endif
