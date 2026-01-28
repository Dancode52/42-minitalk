#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/Headers/libft.h"
#include <stdio.h>


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

void sendasbits(char *string, int pid, struct sigaction sa)
{
	int i;
	int bits;
	(void)sa;

	i = 0;
	//sigaction(SIGUSR1, &sa, NULL);
	while (string[i])
	{
		bits = 0;
		while (bits < 8)
		{
			if (string[i] >> (7 - bits) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bits++;
			usleep(100);
		}
		i++;
	}
	bits = 0;
	while (bits < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		bits++;
	}
}
//------------------------------------------------------

void	signalsend(char *tmep, int pid)
{
	int i = ft_strlen(tmep) - 1;

	while (i >= 0)
	{
		if (tmep[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

void	sendasbitsredux(char *argv, int pid)
{
	int		i;
	int		j;
	char 	*temp;
	char 	toconvert;

	i = 0;
	temp = (char *)malloc(9);
	ft_bzero(temp, 9);
	while (argv[i])
	{
		j = 0;
		toconvert = argv[i];
		while (j < 8)
		{
			temp[j] = (toconvert % 2) + '0';
			toconvert /= 2;
			j++;
		}
		signalsend (temp, pid);
		i++;
	}
	free(temp);
}

void	handler(int signal)
{
	if (signal == 10)
	{
		write(1, "message recieved", 17);
	}
	//exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	struct sigaction sa;
	__pid_t pid;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = &handler;

	if (argc != 3 || charchecker(argv[1]) != 1)
	 	return (0);
	pid = ft_atoi(argv[1]);
	//kill(pid, SIGUSR1);
	sigaction(10, &sa, NULL);
	sendasbits(argv[2], pid, sa);
	sleep(1);
	//sendasbitsredux(argv[2], pid);
}
