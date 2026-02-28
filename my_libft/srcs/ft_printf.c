/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:22:37 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/15 13:43:47 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static ssize_t	ifpointer(size_t ptr)
{
	ssize_t	nbr;

	nbr = 0;
	if (!ptr)
	{
		nbr += write(1, "(nil)", 5);
		return (nbr);
	}
	else
	{
		nbr += write(1, "0x", 2);
		nbr += ft_putuint_base_fd(ptr, "0123456789abcdef", 1);
	}
	return (nbr);
}

static ssize_t	conversions(va_list list, const char formatc)
{
	ssize_t	nbr;

	nbr = 0;
	if (formatc == 'c')
		nbr += ft_putchar_fd(va_arg(list, int), 1);
	if (formatc == 's')
		nbr += ft_putstr_fd(va_arg(list, char *), 1);
	if (formatc == 'p')
		nbr += ifpointer((size_t)va_arg(list, void *));
	if (formatc == 'd' || formatc == 'i')
		nbr += ft_putnbr_fd(va_arg(list, int), 1);
	if (formatc == 'u')
		nbr += ft_putuint_base_fd(va_arg(list, unsigned int), "0123456789", 1);
	if (formatc == 'x')
		nbr += ft_putuint_base_fd
			(va_arg(list, unsigned int), "0123456789abcdef", 1);
	if (formatc == 'X')
		nbr += ft_putuint_base_fd
			(va_arg(list, unsigned int), "0123456789ABCDEF", 1);
	if (formatc == '%')
		nbr += write(1, "%", 1);
	return (nbr);
}

ssize_t	ft_printf(const char *format, ...)
{
	size_t	i;
	ssize_t	charcount;
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
