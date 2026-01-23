#include "../Headers/server.h"
#include "../libft/Headers/libft.h"
#include <stdio.h>


// void	converttobinary(size_t n, char *base, char **res)
// {
// 	size_t	len;
// 	static	int		i;

// 	if (!base)
// 		return ;
// 	//i = 0;
// 	len = ft_strlen(base);
// 	if (n >= len)
// 	{
// 		converttobinary(n / len, base, &(*res));
// 		converttobinary(n % len, base, &(*res));
// 	}
// 	else
// 	{
// 		printf("i = %i\n", i);
// 		(*res)[i] = n + '0';
// 		i++;
// 		if (i == 7)
// 			i = 0;
// 		return ;
// 	}
// 	return ;
// }

// char	*lettertobits(char letter)
// {
// 	//int inbits;
// 	char *res;
// 	res = (char *)malloc(9 * sizeof(char));
// 	ft_bzero(res, 9);
// 	converttobinary(letter, "01", &res);
// 	return (res);
// }

// char	**charstobitarray(char *input)
// {
// 	int	i;
// 	int len;
// 	char **temp;

// 	i = 0;
// 	len = ft_strlen(input);
// 	temp = (char **)malloc((len + 1) * sizeof(char *));
// 	if (!temp)
// 		return (NULL);
// 	temp[len] = NULL;
// 	while (input[i])
// 	{
// 		temp[i] = lettertobits(input[i]);
// 		i++;
// 	}
// 	return (temp);
// }




// void	convertbinaryprint(char *input)
// {
// 	char singleletter;
// 	int j;
// 	j = 0;
// 	//int i;
// //	int counter;

// 	singleletter = 0;
// //	i = 0;
// 	//counter = 0;
// 	// while (input[i])
// 	// {
// 	// 	while (counter < 8)
// 	// 	{
// 	// 		singleletter <<= 1;
// 	// 		if ((input[i] >> (7 - counter)) & 1)
// 	// 			singleletter |= 1;
// 	// 		else
// 	// 			singleletter <<= 1;
// 	// 		counter ++;
// 	// 	}
// 	// 	counter = 0;
// 	// 	i++;
// 	// }
// 	while (j < 8)
// 	{
// 		singleletter <<= 1;
// 		if (input[0] >> (7 - j) & 1)
// 			singleletter |= 1;
// 		j++;
// 	}
// 	printf("%c\n", singleletter);
// 	singleletter = 0;
// 	// for (int i = 7; i >= 0; i--)
// 	// {
// 	// 	singleletter <<= 1;
// 	// 	if ((input[0] >> i) & 1)
// 	// 		singleletter |= 1;
// 	// 	else

// 	// }
// 	printf("%c\n", singleletter);
// 	return ;
// }

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

void sendasbits(char *argv, int pid)
{
	int i;
	int bits;

	i = 0;
	while (argv[i])
	{
		bits = 0;
		while (bits < 8)
		{
			if (argv[i] >> (7 - bits) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bits++;
			usleep(100);
		}
		i++;
	}

}

int	main(int argc, char **argv)
{
	__pid_t pid;
	// char	**stringinbits;
	// int i;

	if (argc != 3 || charchecker(argv[1]) != 1)
		return (0);
	pid = ft_atoi(argv[1]);
	printf("%d\n", pid);
	sendasbits(argv[2], pid);
	//id = ft_atoi(argv[1]);
	//stringinbits = charstobitarray(argv[2]);
	//convertbinaryprint(argv[2]);
	// i = 0;
	// while (stringinbits[i])
	// {
	// 	printf("%c in bits is %s\n", argv[2][i], stringinbits[i]);
	// 	i++;
	// }
}
