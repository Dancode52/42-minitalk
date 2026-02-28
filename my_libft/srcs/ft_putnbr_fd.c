/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:35:46 by dlanehar          #+#    #+#             */
/*   Updated: 2025/10/24 09:38:25 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t	written_chars;

	written_chars = 0;
	if (fd < 0)
		return (-1);
	if (n == -2147483648)
	{
		written_chars += ft_putstr_fd("-2147483648", fd);
		return (written_chars);
	}
	if (n < 0)
	{
		written_chars += ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 0 && n < 10)
		written_chars += ft_putchar_fd(n + '0', fd);
	else
	{
		written_chars += ft_putnbr_fd(n / 10, fd);
		written_chars += ft_putnbr_fd(n % 10, fd);
	}
	return (written_chars);
}
