#include <stdio.h>
#include <stdlib.h>

enum CAT_BREED {MAINE_COON, TABBY, CALICO};

struct cat {
	enum CAT_BREED type;
};

struct cat_maine_coon {
	enum CAT_BREED type;
	void (*call)(void);
};

struct cat_tabby {
	enum CAT_BREED type;
	void (*call)(void);
};

void cat_maine_coon_call(void)
{
	printf("Chirp!\n");
}

void cat_tabby_call(void)
{
	printf("Meow!\n");
}

int main(int argc, char *argv[])
{
	struct cat *a[2];
	
	struct cat_maine_coon *Potter = malloc(sizeof(struct cat_maine_coon));
	Potter->type = MAINE_COON;
	Potter->call = cat_maine_coon_call;
	
	
	struct cat_tabby *Mario = malloc(sizeof(struct cat_tabby));
	Mario->type = TABBY;
	Mario->call = cat_tabby_call;
	
	a[0] = (struct cat*) Potter;
	a[1] = (struct cat*) Mario;
	
	unsigned i = 0;
	for (i = 0; i < 2; i++) {
		if (a[i]->type == MAINE_COON) {
			((struct cat_maine_coon *)a[i])->call();
		} else {
			((struct cat_maine_coon *)a[i])->call();
		}
	}
	
	free(Potter);
	free(Mario);
	
	return 0;
}
