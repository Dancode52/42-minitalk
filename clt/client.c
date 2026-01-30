#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/Headers/libft.h"

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
		usleep(300);
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

//------------------------------------------------------

void sendasbits(char *string, int pid)
{
	int i;
	int bits;

	i = 0;
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
			usleep(300);
		}
		i++;
	}
	bits = 0;
	while (bits < 8)
	{
		usleep(300);
		kill(pid, SIGUSR2);
		bits++;
	}
}

int	main(int argc, char **argv)
{
	__pid_t pid;
	
	if (argc != 3 || charchecker(argv[1]) != 1)
		return (0);
	pid = ft_atoi(argv[1]);
	sendasbits(argv[2], pid);
}
