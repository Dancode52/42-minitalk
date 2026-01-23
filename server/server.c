#include "../Headers/server.h"
#include <stdio.h>
#include <unistd.h>


void handler(int signum)
{
	//write(1, "and it is good! \n", 18);
	static char res;
	static int	counter;

	res <<= 1;
	if (signum == SIGUSR1)
		res |= 1;
	else if (signum == SIGUSR2)
		res |= 0;
	counter++;
	if (counter == 8)
	{
		write(1, &res, 1);
		res = 0;
		counter = 0;
	}

}

int	main()
{
	__pid_t pid;
	struct sigaction sa;

	pid = getpid();
	printf("The PID is %i\n", pid);
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
