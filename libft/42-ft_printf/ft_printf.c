/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:22:37 by dlanehar          #+#    #+#             */
/*   Updated: 2025/12/23 14:11:54 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/ft_printf.h"

static ssize_t	ifpointer(size_t ptr)
{
	ssize_t	count;

	count = 0;
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	else
	{
		count += write(1, "0x", 2);
		count += ft_usiputnbrcount_base_fd(ptr, "0123456789abcdef", 1);
	}
	return (count);
}

static ssize_t	conversions(va_list list, const char formatc)
{
	ssize_t	count;

	count = 0;
	if (formatc == 'c')
		count += ft_putcharcount_fd(va_arg(list, int), 1);
	if (formatc == 's')
		count += ft_putstrcount_fd(va_arg(list, char *), 1);
	if (formatc == 'p')
		count += ifpointer((size_t)va_arg(list, void *));
	if (formatc == 'd' || formatc == 'i')
		count += ft_putnbrcount_fd(va_arg(list, int), 1);
	if (formatc == 'u')
		count += ft_usiputnbrcount_base_fd
			(va_arg(list, unsigned int), "0123456789", 1);
	if (formatc == 'x')
		count += ft_usiputnbrcount_base_fd
			(va_arg(list, unsigned int), "0123456789abcdef", 1);
	if (formatc == 'X')
		count += ft_usiputnbrcount_base_fd
			(va_arg(list, unsigned int), "0123456789ABCDEF", 1);
	if (formatc == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		charcount;
	va_list	list;

	if (!format)
		return (-1);
	i = 0;
	charcount = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			charcount += conversions(list, format[i]);
		}
		else
			charcount += write(1, &format[i], 1);
		i++;
	}
	va_end(list);
	return (charcount);
}
