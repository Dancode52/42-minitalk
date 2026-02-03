/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 08:59:34 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/03 13:56:19 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/server.h"

char	*g_string;

char	*create_char(int signum, int *zerocount, int *bits)
{
	static char	c;
	char		*res;

	res = NULL;
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
	if (*bits == 8)
	{
		res = ft_calloc(2, sizeof(char));
		if (!res)
			return (NULL);
		res[0] = c;
		c = 0;
	}
	return (res);
}

// char	*copy_and_add(char	c, char	*string)
// {
// 	char	*temp;
// 	int		len;

// 	len = ft_strlen(string);
// 	temp = ft_calloc(len + 2, sizeof(char));
// 	if (!temp)
// 		return (NULL);
// 	ft_strlcpy(temp, string, len);
// }

char	*create_string(int signum)
{
	static int	zerocount;
	static int	bits;
	char		*c;
	char		*temp;

	c = create_char(signum, &zerocount, &bits);
	if (bits == 8)
	{
		temp = ft_strjoin(g_string, c);
		if (!temp)
			return (NULL);
		if (g_string)
			free(g_string);
		g_string = temp;
		free(c);
		bits = 0;
		if (zerocount != 8)
			zerocount = 0;
	}
	if (!(zerocount == 8 && bits == 0))
		return (NULL);
	else
		zerocount = 0;
	return (g_string);
}

void	handler(int signum, siginfo_t *info, void *ucontext_t)
{
	(void)ucontext_t;

	if (!create_string(signum))
	{
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	ft_putendl_fd(g_string, 1);
	free(g_string);
	g_string = NULL;
	kill(info->si_pid, SIGUSR1);
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
