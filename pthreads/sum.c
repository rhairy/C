#include <errno.h>
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 10

void *adder(void *num)
{
	int *my_num = (int *)num;
	printf("Before: %i\n", *my_num);
	*my_num = *my_num + 1;
	printf("After: %i\n", *my_num);
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	pthread_t threads[NUM_THREADS];
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
	printf("%i\n", *sum);
	pthread_exit(NULL);
	return 0;
}


