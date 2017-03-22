#include <stdio.h>
#include <stdlib.h>


int gen(void)
{
	return rand() % 10;
}

int fun1(int (*generator)(void))
{
	return gen();
}

int main(int argc, char *argv[])
{
	unsigned i;
	int j;
	for (i = 0; i < 10; i++) {
		j = fun1(gen);	
		printf("%i\n", j);
	}
	return 0;
}
