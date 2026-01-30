#include <stdint.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/Headers/libft.h"
#include <unistd.h>
#include <stdio.h>

char	create_char(int signum, int *zerocount, int *bits)
{
	static char	res;

	res <<= 1;
		printf("made it into create char\n");
	if (signum == SIGUSR1)
	{
		res |= 1;
		*zerocount = 0;
	}
	else if (signum == SIGUSR2)
	{
		res |= 0;
		*zerocount += 1;
	}
	*bits += 1;
	if (*bits == 8)
		res = 0;
	return (res);
}

char	*create_string(int	signum)
{
	static int	zerocount;
	static int	bits;
	char c;
	static char	*string;
	char	*temp;

		printf("made it into create string\n");
	temp = NULL;
	c = create_char(signum, &zerocount, &bits);
	if (bits == 8)
	{
		if (string)
		{
			temp = ft_strdup(string);
			free(string);
			string = NULL;
		}
		if (temp)
		{
			string = ft_strjoin(temp, &c);
			free(temp);
			temp = NULL;
		}
		else
		 	string = ft_strjoin(NULL, &c);
		//string = (char *)ft_calloc(2, sizeof(char));
		//string[0] = c;
		bits = 0;
	}
	printf("zerocount = %i\n", zerocount);
	if (zerocount == 8)
		return (string);
	return (NULL);
}

void	print_string(int signum)
{
	char	*string;
	int		len;

	printf("made it into print string\n");
	string = create_string(signum);
	if (!string)
		return ;
	len = 0;
	while (string[len])
		len++;
	write(1, string, len);
	write(1, "\n", 1);
}

void	handler(int signum, siginfo_t *info, void *ucontext_t)
{
	(void)ucontext_t;
	int lol;
	static int i;

	printf("%i\n", i);
	i += 1;
	lol = (info->si_pid) - (info->si_pid) + 1;
	//ft_putnbr_fd(lol, 1);
	//write(1, "\n", 1);
	print_string(signum);
}

int	main()
{
	__pid_t 		pid;
	struct sigaction sa;
	//int i;

	ft_bzero(&sa, sizeof(sa));
	pid = getpid();
	printf("The PID is %i\n", pid);
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

