#include <errno.h>
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 10

void *adder(void *num);
pthread_mutex_t mut;
	
int main(int argc, char* argv[])
{
	pthread_t threads[NUM_THREADS];
	
	pthread_mutex_init(&mut, NULL);
	
	int res;
	unsigned i;
	int *sum;
	*sum = 0;
	for (i = 0; i < NUM_THREADS; i++) {
		res = pthread_create(&threads[i], NULL, adder, (void *) sum);
		if (res) {
			perror("pthread_create()");
		}
	}
	
	for (i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}
	
	printf("%i\n", *sum);
	pthread_exit(NULL);
	return 0;
}

void *adder(void *num)
{
	pthread_mutex_lock(&mut);
	int *my_num = (int *)num;
	printf("Before: %i\n", *my_num);
	*my_num = *my_num + 1;
	printf("After: %i\n", *my_num);
	pthread_mutex_unlock(&mut);
	pthread_exit(NULL);
}
