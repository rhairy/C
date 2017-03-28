#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 50

void insertion_sort(void *a, size_t len, int (*compare)(void *a, unsigned x, unsigned y), void (*swap)(void *a, unsigned x, unsigned y));
int is_x_gt_y(void *a, unsigned x, unsigned y);
void swap_int(void *a, unsigned x, unsigned y);

int main(int argc, char* argv[])
{	
	int x;
	int a[LEN];
	unsigned i;
	
	srand(time(NULL));
	
	for (i = 0; i < LEN; i++) {
		x = rand() % 1000;
		a[i] = x;
	}
	
	for (i = 0; i < LEN; i++) {
		printf("%i ", a[i]);
	}
	
	insertion_sort (a, LEN, is_x_gt_y, swap_int);
	
	printf("\n");
	
	for (i = 0; i < LEN; i++) {
		printf("%i ", a[i]);
	}
	
	return 0;
}

void insertion_sort(void *a, size_t len, int (*compare)(void *a, unsigned x, unsigned y), void (*swap)(void *a, unsigned x, unsigned y))
{
	unsigned i, j;
	for (i = 0; i < len; i++) {
		for (j = i; j > 0; j--) {
			if (compare(a, j, j-1)) {
				swap(a, j, j-1);
			}
		}
	}
}

int is_x_gt_y(void *a, unsigned x, unsigned y) 
{
	int* ia = a;
	if (ia[x] > ia[y]) {
		return 0;
	} else {
		return 1;
	}
}

void swap_int(void *a, unsigned x, unsigned y)
{
	int *ia = a;
	int tmp;
	tmp = ia[x];
	ia[x] = ia[y];
	ia[y] = tmp;
}