/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:13:51 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/15 13:43:47 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	nbr_len(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*min_or_zero(int n)
{
	char	*res;

	if (n == -2147483648)
	{
		res = ft_strdup("-2147483648");
		if (!res)
			return (NULL);
		return (res);
	}
	else if (n == 0)
	{
		res = ft_strdup("0");
		if (!res)
			return (NULL);
		return (res);
	}
	return (NULL);
}

static char	*print_nbr(int n)
{
	int		size;
	char	*str;

	size = nbr_len(n) + 1;
	str = ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	size--;
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n > 0)
	{
		size--;
		str[size] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*ptr;

	if (n == -2147483648 || n == 0)
	{
		ptr = min_or_zero(n);
		return (ptr);
	}
	ptr = print_nbr(n);
	return (ptr);
}
