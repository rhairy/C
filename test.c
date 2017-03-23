#include <stdio.h>
#include <stdlib.h>

struct cat {
	unsigned type; // MaineCoon = 0, Tabby = 1
};

struct cat_maine_coon {
	struct cat super;
	void (*call)(void);
};

struct cat_tabby {
	struct cat super;
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
	Potter->super.type = 0;
	Potter->call = cat_maine_coon_call;
	
	
	struct cat_tabby *Mario = malloc(sizeof(struct cat_tabby));
	Mario->super.type = 1;
	Mario->call = cat_tabby_call;
	
	a[0] = (struct cat*) Potter;
	a[1] = (struct cat*) Mario;
	
	unsigned i = 0;
	for (i = 0; i < 2; i++) {
		if (a[i]->type == 0) {
			((struct cat_maine_coon *)a[i])->call();
		} else {
			((struct cat_maine_coon *)a[i])->call();
		}
	}
	return 0;
}