#include <stdio.h>
#include <stdlib.h>

const unsigned LEN = 20;

enum TYPE {A, B, C};

struct super {
	enum TYPE t;
};

struct subA {
	enum TYPE t;
	unsigned val;
};

struct subB {
	enum TYPE t;
	char val;
};

int main(int argc, char* argv[])
{
	unsigned i;
	/* Dynamically allocate memory and add structs. */
	struct super** arr = malloc(sizeof(struct super*) * LEN);
	
	for (i = 0; i < LEN; i++) {
		if (i % 2 == 0) {
			struct subA* tmp;
			arr[i] = malloc(sizeof(struct subA));
			tmp = (struct subA*) arr[i];
			tmp->t = A;
			tmp->val = i;
		} else {
			struct subB* tmp;
			arr[i] = malloc(sizeof(struct subB));
			tmp = (struct subB*) arr[i];
			tmp->t = B;
			tmp->val = i + 65;
		}
	}
	
	for (i = 0; i < LEN; i++) {
		if (arr[i]->t == A) {
			struct subA* tmp;
			tmp = (struct subA*) arr[i];
			printf("%i\n", tmp->val);
		}
		else if (arr[i]->t == B) {
			struct subB* tmp;
			tmp = (struct subB*) arr[i];
			printf("%c\n", tmp->val);
		}
	}
	
	/* Free dynamically allocated memory. */
	for (i = 0; i < LEN; i++) {
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	
	return 0;
}
