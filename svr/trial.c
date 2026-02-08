#include "../Headers/server.h"

char	create_char(int signum, int *bits)
{
	static char	c = 0;

	if (*bits == 0)
		c = 0;
	c <<= 1;
	if (signum == SIGUSR1)
		c |= 1;
	*bits += 1;
	return (c);
}

// size_t	ft_herestrlen(char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s || s[0] == '\0')
// 		return (0);
// 	while (s[i])
// 		i++;
// 	return (i);
// }
// #include <stdio.h>
// void	appendletter(char **string, char c)
// {
// 	int		len;
// 	int		i;
// 	char	*temp;

// 	len = ft_herestrlen(*string);
// 	i = 0;
// 	temp = malloc(len + 2);
// 	while ((*string)[i])
// 	{
// 		temp[i] = (*string)[i];
// 		i++;
// 	}
// 	temp[i] = c;
// 	temp[i + 1] = 0;
// 	free(*string);
// 	*string = temp;
// }

// int	create_string(int signum, char **string)
// {
// 	static int	zerocount;
// 	static int	bits;
// 	char		c;

// 	if (!*string)
// 		*string = ft_strdup("");
// 	c = create_char(signum, &zerocount, &bits);
// 	if (bits == 8)
// 	{
// 		appendletter(string, c);
// 		bits = 0;
// 		if (c == 0)
// 			return (1);
// 	}
// 	return (0);
// }

void	reset(char *c, int *bits, int *i, int *pid)
{
	*c = 0;
	*bits = 0;
	*i = 0;
	*pid = 0;
}

void	handler(int signum, siginfo_t *info, void *ucontext_t)
{
	static char	string[10000];
	static char	c;
	static int	bits;
	static int	i;
	static int	pid;

	(void)ucontext_t;
	c = create_char(signum, &bits);
	if (!pid)
		pid = info->si_pid;
	if (bits == 8)
	{
		string[i++] = c;
		if (!c)
		{
			ft_putendl_fd(string, 1);
			reset(&c, &bits, &i, &pid);
		}
		bits = 0;
		c = 0;
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
