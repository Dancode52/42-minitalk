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

int	main(int argc, char **argv)
{
	__pid_t id;
	int	lettervalue;
	int	i;

	if (argc != 3 || charchecker(argv[1]) != 1)
	{
		printf("dasjkdha\n");
		return (0);
	}
	id = ft_atoi(argv[1]);
	lettervalue = argv[2][0];
	printf("%i\n", lettervalue);
	i = 0;
	while (i < lettervalue)
	{
		kill(id, SIGUSR1);
		i++;
		//printf("%i\n", i);
	}
	printf("id is %i\n", id);

	//printf("yo we sent them the goods... hope they like it\n");
	sleep(2);
	//kill(id, SIGUSR2);
}
