#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 100000

int main(int argc, char* argv[])
{
	clock_t start, end, cpu_time;
	int a[LEN];
	unsigned i;

	srand(time(NULL));
	
	start = clock();
	for (i = 0; i < LEN; i++) {
		a[i] = rand() % LEN;
		printf("%i ", a[i]);
	}
	printf("\n");
	end = clock();

	cpu_time = start - end;
	
	printf("%Lf\n", cpu_time);
	return 0;
}
