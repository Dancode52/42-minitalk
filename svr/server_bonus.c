/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:00:40 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/28 14:26:45 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/server.h"

char g_gchar = 0;

void	appendletter(char **string)
{
	int		len;
	int		i;
	char	*temp;

	len = ft_strlen((*string));
	i = 0;
	temp = malloc(len + 2);
	while ((*string)[i])
	{
		temp[i] = (*string)[i];
		i++;
	}
	temp[i] = g_gchar;
	temp[i + 1] = 0;
	free((*string));
	(*string) = temp;
}

int	create_string(char **string)
{
	static int	bits;
	// char		c;

	if (!*string)
		*string = ft_strdup("");
	bits++;
	if (bits == 8)
	{
		appendletter(string);
		bits = 0;
		if (g_gchar == 0)
			return (1);
	}
	return (0);
}

void	print_string(void)
{
	static char *string;
	int flag;

	flag = create_string(&string);
	if (flag)
	{
		ft_printf("%s\n", string);
		free(string);
		string = NULL;
		g_gchar = 0;
	}
}

void	handler(int signum, siginfo_t *info, void *ucontext_t)
{
	(void)ucontext_t;
	static int	pid;
	static int	bits;

	if (!pid)
		pid = info->si_pid;
	if (info->si_pid == pid)
	{
		bits++;
		g_gchar <<= 1;
		if (signum == SIGUSR1)
			g_gchar |= 1;
		else
			g_gchar |= 0;
		kill(info->si_pid, SIGUSR1);
	}
	if (bits >= 8 && g_gchar == '\0')
	{
		pid = 0;
		kill(info->si_pid, SIGUSR2);
	}
	if (bits >= 8)
		bits = 0;

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
		print_string();
	}
}
