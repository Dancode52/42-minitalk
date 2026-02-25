/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:15:31 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/25 09:42:16 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/server.h"

int	g_ack = 0;

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

void	handler(int signum)
{
	if (signum == SIGUSR1)
		g_ack = 1;
	if (signum == SIGUSR2)
	{
		write(1, "Message sent succesfully\n", 25);
		g_ack = 0;
	}
	return ;
}

void	init_sigaction_struct(struct sigaction *structname)
{
	ft_bzero(&(*structname), sizeof((*structname)));
	(*structname).sa_handler = &handler;
	sigemptyset(&(*structname).sa_mask);
	sigaction(SIGUSR1, &(*structname), NULL);
	sigaction(SIGUSR2, &(*structname), NULL);
}

void	sendasbits(char *string, int pid)
{
	int					i;
	int					len;
	struct sigaction	sa;
	int					bits;

	i = 0;
	len = ft_strlen(string);
	init_sigaction_struct(&sa);
	while (i <= len)
	{
		bits = 0;
		while (bits < 8)
		{
			if (string[i] >> (7 - bits) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!g_ack)
				pause();
			g_ack = 0;
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
