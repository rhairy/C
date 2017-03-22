#include <errno.h>
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 10

void *hello(void *id)
{
	printf("Hello from thread: %i\n", (unsigned) id);
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	pthread_t threads[NUM_THREADS];
	int res;
	unsigned i;
	unsigned *pld;
	for (i = 0; i < NUM_THREADS; i++) {
		res = pthread_create(&threads[i], NULL, hello, (void *) i);
		if (res) {
			perror("pthread_create()");
		}
	}
	pthread_exit(NULL);
	return 0;
}


