#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "alg.h"

#define LEN 10

int is_x_gt_y(void *a, size_t x, size_t y);
void swap_int(void *a, size_t x, size_t y);
void print_int(void *a, size_t i);
void print_array(void *a, size_t len, void (*print_function)(void *a, size_t index));

int main(int argc, char* argv[])
{	
	int x;
	int a[LEN];
	int b[LEN];
	int c[LEN];
	unsigned i;
	
	srand(time(NULL));
	
	/* Seed array with random numbers. */
	for (i = 0; i < LEN; i++) {
		x = rand() % 1000;
		a[i] = x;
		b[i] = x;
		c[i] = x;
	}
	
	/* Bubble Sort. */
	printf("*** Bubble Sort ***\n");
	print_array(a, LEN, print_int);
	bubble_sort(a, LEN, is_x_gt_y, swap_int);
	print_array(a, LEN, print_int);
	
	/* Insertion Sort. */
	printf("*** Insertion Sort ***\n");
	print_array(b, LEN, print_int);
	insertion_sort(b, LEN, is_x_gt_y, swap_int);
	print_array(b, LEN, print_int);
	
	/* Selection Sort. */
	printf("*** Selection Sort ***\n");
	print_array(c, LEN, print_int);
	selection_sort(c, LEN, is_x_gt_y, swap_int);
	print_array(c, LEN, print_int);
	
	return 0;
}

int is_x_gt_y(void *a, size_t x, size_t y) 
{
	int* ia = a;
	if (ia[x] > ia[y]) {
		return 1;
	} else {
		return 0;
	}
}

void swap_int(void *a, size_t x, size_t y)
{
	int *ia = a;
	int tmp;
	tmp = ia[x];
	ia[x] = ia[y];
	ia[y] = tmp;
}

void print_int(void *a, size_t i)
{
	int* tmp = a;
	printf("%i ", tmp[i]);
}

void print_array(void *a, size_t len, void (*print_function)(void *a, size_t index))
{
	unsigned i;
	for (i = 0; i < len; i++) {
		print_function(a, i);
	}
	printf("\n");
}