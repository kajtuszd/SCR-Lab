#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

volatile int i;
volatile int j;

void check(int sig)
{
	printf("Signal %d\n", sig);
	switch(sig)
	{
		case 14:
			printf("Alarm");
			break;

		case 15:
			printf("Terminated");
			exit(1);
			break;

		case 16:
			if (j)
			{
				printf("Stopped receiving");
				j = 0;
				i = 0;
			}
			break;

		case 17:
			break;

		default:
			printf("Undefined signal");
			break;
	}
}


int main()
{
	i = 0;
	j = 1;

	struct timespec tm1, tm2;
	tm1.tv_sec = 0;
	tm1.tv_nsec = 100 * 1000000;
	signal(SIGINT, check);
	printf("%d", SIGINT);

	while(1)
	{
		i++;
		if(!j && i>1000)
			j = 1;
		nanosleep(&tm1, &tm2); 
	}
	return 0;

}







