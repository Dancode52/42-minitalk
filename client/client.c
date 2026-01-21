#include "../Headers/server.h"
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

void	converttobinary(size_t n, char *base, char **res)
{
	size_t	len;
	static	int		i;

	if (!base)
		return ;
	//i = 0;
	len = ft_strlen(base);
	if (n >= len)
	{
		converttobinary(n / len, base, &(*res));
		converttobinary(n % len, base, &(*res));
	}
	else
	{
		printf("i = %i\n", i);
		(*res)[i] = n + '0';
		i++;
		if (i == 7)
			i = 0;
		return ;
	}
	return ;
}

char	*lettertobits(char letter)
{
	//int inbits;
	char *res;
	res = (char *)malloc(9 * sizeof(char));
	ft_bzero(res, 9);
	converttobinary(letter, "01", &res);
	return (res);
}

char	**charstobitarray(char *input)
{
	int	i;
	int len;
	char **temp;

	i = 0;
	len = ft_strlen(input);
	temp = (char **)malloc((len + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	temp[len] = NULL;
	while (input[i])
	{
		temp[i] = lettertobits(input[i]);
		i++;
	}
	return (temp);
}

int	main(int argc, char **argv)
{
	//__pid_t id;
	char	**stringinbits;
	int i;

	if (argc != 3 || charchecker(argv[1]) != 1)
		return (0);
	//id = ft_atoi(argv[1]);
	stringinbits = charstobitarray(argv[2]);
	i = 0;
	while (stringinbits[i])
	{
		printf("%c in bits is %s\n", argv[2][i], stringinbits[i]);
		i++;
	}
}
