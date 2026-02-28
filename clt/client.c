/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:05:31 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/28 14:23:58 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/server.h"

int	charchecker(char *check)
{
	int	i;

	i = 0;
	while (check[i])
	{
		if (ft_isdigit(check[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	sendasbits(char *string, int pid)
{
	int					i;
	int					len;
	int					bits;

	i = 0;
	len = ft_strlen(string);
	while (i <= len)
	{
		bits = 0;
		while (bits < 8)
		{
			if (string[i] >> (7 - bits) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bits++;
			usleep(380);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	__pid_t	pid;

	if (argc != 3 || charchecker(argv[1]) != 1)
		return (0);
	pid = ft_atoi(argv[1]);
	sendasbits(argv[2], pid);
}
