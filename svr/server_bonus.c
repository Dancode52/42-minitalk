#include <stdlib.h>
#include <signal.h>
#include "../libft/Headers/libft.h"
#include <unistd.h>
#include <stdio.h>


char *g_recieved;

// void	handler(int signum)
// {
// 	static char res;
// 	static int	counter;
// 	static int i;

// 	res <<= 1;
// 	if (signum == SIGUSR1)
// 		res |= 1;
// 	else if (signum == SIGUSR2)
// 		res |= 0;
// 	counter++;
// 	if (counter == 8)
// 	{
// 		//write(1, &res, 1);
// 		res = 0;
// 		counter = 0;
// 		if (res == '\0')

// 	}

// }


void	handler_bonus(int signum, siginfo_t *info, void *ucontext_t)
{
	static char res;
	static int	counter;
	char *tmp;
	static int zerocount;
	(void)ucontext_t;

	// if (!g_recieved)
	// 	g_recieved = ft_calloc(1, sizeof(char));
	// if (!g_recieved)
	// 	exit (EXIT_FAILURE);
	res <<= 1;
	if (signum == SIGUSR1)
	{
		res |= 1;
		zerocount = 0;
	}
	else if (signum == SIGUSR2)
	{
		res |= 0;
		zerocount++;
	}
	counter++;
	kill(info->si_pid, SIGUSR1);
	if (counter == 8)
	{
		char *temp = ft_calloc(2, sizeof(char));
		temp[0] = res;
		tmp = ft_strjoin(g_recieved, temp);
		free(g_recieved);
		free(temp);
		g_recieved = tmp;
		//free(tmp);
		res = 0;
		counter = 0;
		//printf("%s\n", g_recieved);
		if (zerocount == 8) //|| g_recieved[len] == 'e')
		{
			write(1, g_recieved, ft_strlen(g_recieved));
			write(1, "\n", 1);
			free(g_recieved);
			g_recieved = NULL;
		}
	}
}

// int binarytodecimal(int bin)
// {
// 	int decimal;
// 	int base;
// 	int lastdigit;

// 	base = 1;
// 	decimal = 0;
// 	while (bin)
// 	{
// 		lastdigit = bin % 10;
// 		bin = bin / 10;
// 		decimal += lastdigit * base;
// 		base = base * 2;
// 	}
// 	return (decimal);
// }

// void	handler(int signum)
// {
// 	static char temp[9];
// 	static int i;
// 	int tempi;
// 	char tempc;

// 	if (signum == SIGUSR1)
// 	{
// 		temp[i] = '1';
// 		i++;
// 	}
// 	else
// 	{
// 		temp[i] = '0';
// 		i++;
// 	}
// 	if (i == 8)
// 	{
// 		tempi = ft_atoi(temp);
// 		tempc = binarytodecimal(tempi);
// 		write(1, &tempc, 1);
// 		i = 0;
// 	}
// }

// int	main()
// {
// 	__pid_t 		pid;
// 	struct sigaction act;

// 	pid = getpid();
// 	printf("The PID is %i\n", pid);
// 	sa.sa_handler = handler;
// 	sigemptyset(&sa.sa_mask);
// 	sa.sa_flags = 0;
// 	sigaction(SIGUSR1, &sa, NULL);
// 	sigaction(SIGUSR2, &sa, NULL);
// 	while (1)
// 	{
// 		pause();
// 	}
// }


int	main()
{
	__pid_t 		pid;
	struct sigaction sa;
	//int i;

	ft_bzero(&sa, sizeof(sa));
	pid = getpid();
	printf("The PID is %i\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler_bonus;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}

