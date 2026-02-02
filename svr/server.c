
#include "../Headers/server.h"

char	*g_string;

char	*create_char(int signum, int *zerocount, int *bits)
{
	static char	c;
	char		*res;

	res = NULL;
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
	if (*bits == 8)
	{
		res = ft_calloc(2, sizeof(char));
		res[0] = c;
	}
	return (res);
}

char	*create_string(int	signum)
{
	static int	zerocount;
	static int	bits;
	char 		*c;
	char		*temp;

	temp = NULL;
	c = create_char(signum, &zerocount, &bits);
	if (bits == 8)
	{
		temp = ft_strjoin(g_string, c);
		if (g_string && ft_strnstr(temp, g_string, ft_strlen(temp)))
		{
			free(g_string);
			g_string = NULL;
		}
		g_string = ft_strdup(temp);
		free(temp);
		free(c);
		bits = 0;
		if (zerocount != 8)
			zerocount = 0;
	}
	if (zerocount == 8 && bits == 0)
	{
		zerocount = 0;
		return (g_string);
	}
	return (NULL);
}

void	print_string(int signum)
{
	char	*string;

	string = create_string(signum);
	if (!string)
		return ;
	ft_putendl_fd(string, 1);
	free(g_string);
	g_string = NULL;
	string = NULL;
	return ;
}

void	handler(int signum, siginfo_t *info, void *ucontext_t)
{
	(void)ucontext_t;

	print_string(signum);
	kill(info->si_pid, SIGUSR1);
}

int	main()
{
	__pid_t 		pid;
	struct sigaction sa;

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

