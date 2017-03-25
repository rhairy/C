#include <errno.h>
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 10

void *hello(void *id)
{	
	unsigned *my_id = (unsigned *) id;
	printf("Hello from thread: %i\n", *my_id);
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	pthread_t threads[NUM_THREADS];
	int res;
	unsigned i;
	unsigned *j;
	*j = 0;
	for (i = 0; i < NUM_THREADS; i++) {
		res = pthread_create(&threads[i], NULL, hello, (void *) j);
		if (res) {
			perror("pthread_create()");
		}
		*j = *j + 1;
	}
	pthread_exit(NULL);
	return 0;
}


