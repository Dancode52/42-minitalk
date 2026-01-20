#include "../Headers/server.h"
#include <stdio.h>

int globali = 0;

void handler1()
{
	globali++;
	//write(1, "we got it boss! \n", 18);
	//*track += 1;
}

void handler2()
{
	write(1, "and it is good! \n", 18);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	__pid_t id;
	//void	(*f)(int *);
	//f = &handler1;
	//struct sigaction act;
//	act.sa_handler = handler1;

	id =  getpid();
	printf("The PID is %i\n", id);
	signal(SIGUSR1, handler1);
	//sigaction(SIGUSR1, &act, NULL);
	if (globali == 'H')
	{
		printf("HOORAY!! WE DID IT!\n");
		return (0);
	}
	//sigaction(SIGUSR2, &act, NULL);
	//signal(SIGUSR2, handler2);
	while (1)
	{
		printf("%i\n", globali);
		printf("Looping\n");
		sleep(1);
	}
}
