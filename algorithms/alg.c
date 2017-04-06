#include <stdlib.h>

void bubble_sort(void *a, size_t len, int (*compare)(void *a, size_t x, size_t y), void (*swap)(void *a, size_t x, size_t y))
{
	unsigned i, j;
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - 1 - i; j++) {
			if (compare(a, j + 1, j)) {
				swap(a, j, j + 1);
			}
		}
	}
}

void insertion_sort(void *a, size_t len, int (*compare)(void *a, size_t x, size_t y), void (*swap)(void *a, size_t x, size_t y))
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

void selection_sort(void *a, size_t len, int (*compare)(void *a, size_t x, size_t y), void (*swap)(void *a, size_t x, size_t y))
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