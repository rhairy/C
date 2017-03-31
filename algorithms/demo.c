#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "alg.h"

#define LEN 10

int is_x_gt_y(void *a, unsigned x, unsigned y);
void swap_int(void *a, unsigned x, unsigned y);
void print_int(void *a, unsigned i);
void print_array(void *a, size_t len, void (*print_function)(void *a, unsigned index));

int main(int argc, char* argv[])
{	
	int x;
	int a[LEN];
	unsigned i;
	
	srand(time(NULL));
	
	/* Seed array with random numbers. */
	for (i = 0; i < LEN; i++) {
		x = rand() % 1000;
		a[i] = x;
	}
	
	/* Print array, sort, and print result. */
	print_array(a, LEN, print_int);
	insertion_sort (a, LEN, is_x_gt_y, swap_int);
	printf("\n");
	print_array(a, LEN, print_int);
	
	return 0;
}

int is_x_gt_y(void *a, unsigned x, unsigned y) 
{
	int* ia = a;
	if (ia[x] > ia[y]) {
		return 1;
	} else {
		return 0;
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

void print_int(void *a, unsigned i)
{
	int* tmp = a;
	printf("%i ", tmp[i]);
}

void print_array(void *a, size_t len, void (*print_function)(void *a, unsigned index))
{
	unsigned i;
	for (i = 0; i < len; i++) {
		print_function(a, i);
	}
}