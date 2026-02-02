#include <stdint.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/Headers/libft.h"
#include <unistd.h>
#include <stdio.h>

char	*g_string;

char	*create_char(int signum, int *zerocount, int *bits)
{
	static char	c;
	char		*res;

	res = NULL;
	if (*bits == 0)
		c = 0;
	c <<= 1;
		//printf("made it into create char\n");
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
	//printf("bits: %i\n", *bits);
	if (*bits == 8)
	{
		res = ft_calloc(2, sizeof(char));
		res[0] = c;
	}
	// if (*zerocount > 8 && *bits != 8)
	// 	*zerocount = 0;
	return (res);
}

char	*create_string(int	signum)
{
	static int	zerocount;
	static int	bits;
	char 		*c;
	//static char	*string;
	char		*temp;

		//printf("made it into create string\n");
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

		// if (string)
		// {
		// 	write(1, "bitch work\n", 12);
		// 	free(string);
		// }
		// if (string != NULL)
		// {
		// 	free(string);
		// }
		// if (string)
		// {
		// 	temp = ft_strdup(string);
		// 	free(string);
		// 	string = NULL;
		// }
		// if (temp)
		// {
		// 	string = ft_strjoin(temp, &c);
		// 	free(temp);
		// 	temp = NULL;
		// }
		// else
		//  	string = ft_strjoin(NULL, &c);
		bits = 0;
		if (zerocount != 8)
			zerocount = 0;
	}
	//printf("zerocount = %i\n", zerocount);
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
	//int		len;

	//printf("made it into print string\n");
	string = create_string(signum);
	if (!string)
		return ;
	// len = 0;
	// while (string[len])
	// 	len++;
	ft_putendl_fd(string, 1);
	free(g_string);
	g_string = NULL;
	string = NULL;
	// write(1, string, len);
	// write(1, "\n", 1);
	return ;
}

void	handler(int signum, siginfo_t *info, void *ucontext_t)
{
	(void)ucontext_t;

	//printf("%i\n", i);
	//ft_putnbr_fd(lol, 1);
	//write(1, "\n", 1);
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

