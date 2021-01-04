#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#define THREADS_NUMBER 10


void *print_hello(void *thread_id)
{
	sleep(1);
	long task_id = (int)thread_id;
	printf("Hello SCR. Written by thread ID: %ld \n", task_id);
	pthread_exit(NULL);
}


int main(int argc, char const *argv[])
{
	pthread_t threads[THREADS_NUMBER];
	for(int i=0; i<THREADS_NUMBER; i++)
	{
		int thread = pthread_create(&threads[i], NULL, print_hello, (void *)i);
	}
	pthread_exit(NULL);
}