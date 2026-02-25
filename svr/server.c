/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 08:59:34 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/16 09:47:17 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/server.h"

char	create_char(int signum, int *zerocount, int *bits)
{
	static char	c = 0;

	if (*bits == 0)
		c = 0;
	c <<= 1;
	if (signum == SIGUSR1)
	{
		c |= 1;
		*zerocount = 0;
	}
	else if (signum == SIGUSR2)
	{
		c |= 0;
		*zerocount += 1;
	}
	*bits += 1;
	return (c);
}

void	appendletter(char **string, char c)
{
	int		len;
	int		i;
	char	*temp;

	len = ft_strlen(*string);
	i = 0;
	temp = malloc(len + 2);
	while ((*string)[i])
	{
		temp[i] = (*string)[i];
		i++;
	}
	temp[i] = c;
	temp[i + 1] = 0;
	free(*string);
	*string = temp;
}

int	create_string(int signum, char **string)
{
	static int	zerocount;
	static int	bits;
	char		c;

	if (!*string)
		*string = ft_strdup("");
	c = create_char(signum, &zerocount, &bits);
	if (bits == 8)
	{
		appendletter(string, c);
		bits = 0;
		if (c == 0)
			return (1);
	}
	return (0);
}

void	handler(int signum, siginfo_t *info, void *ucontext_t)
{
	static char	*string = NULL;
	static int	pid = 0;

	(void)ucontext_t;
	if (!pid)
		pid = info->si_pid;
	if (info->si_pid == pid)
	{
		if (!create_string(signum, &string))
		{
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		ft_putendl_fd(string, 1);
		free(string);
		string = NULL;
		pid = 0;
		kill(info->si_pid, SIGUSR1);
	}
	return ;
}

int	main(void)
{
	__pid_t				pid;
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	pid = getpid();
	write(1, "The PID is ", 12);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
