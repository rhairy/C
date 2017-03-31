#include <stdlib.h>

void insertion_sort(void *a, size_t len, int (*compare)(void *a, unsigned x, unsigned y), void (*swap)(void *a, unsigned x, unsigned y))
{
	unsigned i, j;
	for (i = 1; i < len; i++) {
		j = i;
		while(j > 0 && compare(a, j, j-1)) {
				swap(a, j, j-1);
				j--;
		}
	}
}

void selection_sort(void *a, size_t len, int (*compare)(void *a, unsigned x, unsigned y), void (*swap)(void *a, unsigned x, unsigned y))
{
	unsigned i, j, min;
	for (i = 0; i <= len - 2; i++) {
		min = i;
		for (j = i+1; j < len; j++) {
			if (compare(a, j, min)) {
				min = j;
			}
		}
		swap(a, i, min);
	}
}