#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define THREADS_NUMBER 30
#define ITERATIONS_NUMBER 1000000


struct points
{
	int in_square;
	int in_circle;
	double generated_x;
	double generated_y;
	int result;
};


void *monte_carlo(void *data_array)
{
	struct points *receiver;
	receiver = (struct points *) data_array; 
	receiver->in_square = 0;
	receiver->in_circle = 0;
	
	for(int i=0; i<ITERATIONS_NUMBER; i++)
	{
		receiver->generated_y = drand48();
		receiver->generated_x = drand48();
		if(receiver->generated_x*receiver->generated_x + 
			receiver->generated_y*receiver->generated_y <= 1)
		{
			receiver->in_circle += 1;
		}
		receiver->in_square += 1;
	}
	pthread_exit(NULL);
}


int main(int argc, char const *argv[])
{
	pthread_t threads[THREADS_NUMBER];
	struct points thread_data_array[THREADS_NUMBER];
	double results[THREADS_NUMBER];
	void *status;
	srand48(time(0));

	for(int i=0; i<THREADS_NUMBER; i++)
	{
		int flag = pthread_create(&threads[i], NULL, monte_carlo, (void *) &thread_data_array[i]);
	}

	double sum = 0;
	for(int i=0; i<THREADS_NUMBER; i++)
	{
		printf("Iteration: %d\n", i+1);
		int flag = pthread_join(threads[i], &status);
		printf("In circle %d\n", thread_data_array[i].in_circle);
		printf("In square %d\n", thread_data_array[i].in_square);
		double pi = 4.*(double)thread_data_array[i].in_circle/thread_data_array[i].in_square;
		printf("PI %f\n\n", pi);
		sum += pi;
	}
	printf("\n----------\n");	
	printf("Result %f \n", sum/THREADS_NUMBER);
	pthread_exit(NULL);
}