#include <stdio.h>
#include <stdlib.h>

void insertion_sort(void *a, size_t len, int (*compare)(void *a, unsigned x, unsigned y), void (*swap)(void *a, unsigned x, unsigned y));
int is_x_gt_y(int *a, unsigned x, unsigned y);
void swap_int(int *a, unsigned x, unsigned y);

int main(int argc, char* argv[])
{	
	int a[10];
	int x;
	
	unsigned i;
	for (i = 0; i < 10; i++) {
		x = rand() % 10;
		a[i] = x;
	}
	
	for (i = 0; i < 10; i++) {
		printf("%i ", a[i]);
	}
	
	insertion_sort (a, 10, is_x_gt_y, swap_int);
	
	printf("\n");
	
	for (i = 0; i < 10; i++) {
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

int is_x_gt_y(int *a, unsigned x, unsigned y) 
{
	if (a[x] > a[y]) {
		return 0;
	} else {
		return 1;
	}
}

void swap_int(int *a, unsigned x, unsigned y)
{
	int tmp;
	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}