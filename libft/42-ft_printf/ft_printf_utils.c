/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:49:48 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/04 18:20:58 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/ft_printf.h"
#include "../Headers/libft.h"

ssize_t	ft_putcharcount_fd(char c, int fd)
{
	ssize_t	i;

	i = 0;
	if (fd < 0)
		return (-1);
	i += write(fd, &c, 1);
	return (i);
}

ssize_t	ft_putnbrcount_fd(int n, int fd)
{
	ssize_t	i;

	i = 0;
	if (fd < 0)
		return (-1);
	if (n == -2147483648)
	{
		i += ft_putstrcount_fd("-2147483648", fd);
		return (i);
	}
	if (n < 0)
	{
		i += ft_putcharcount_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
	{
		i += ft_putnbrcount_fd(n / 10, fd);
		i += ft_putnbrcount_fd(n % 10, fd);
	}
	else
		i += ft_putcharcount_fd(n + '0', fd);
	return (i);
}

ssize_t	ft_putstrcount_fd(char *s, int fd)
{
	ssize_t	i;

	i = 0;
	if (!s)
	{
		s = "(null)";
		i += write(fd, s, ft_strlen(s));
		return (i);
	}
	if (fd < 0)
		return (-1);
	i += write(fd, s, ft_strlen(s));
	return (i);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

ssize_t	ft_usiputnbrcount_base_fd(size_t n, char *base, int fd)
{
	size_t	len;
	int		i;

	if (!base)
		return (-1);
	i = 0;
	len = ft_strlen(base);
	if (n >= len)
	{
		i += ft_usiputnbrcount_base_fd(n / len, base, fd);
		i += ft_usiputnbrcount_base_fd(n % len, base, fd);
	}
	else
		i += ft_putcharcount_fd(base[n], fd);
	return (i);
}
