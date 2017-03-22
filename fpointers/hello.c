#include <stdio.h>

void fun1(void (*print_fun)(void))
{
	print_fun();
}

void fun2(void)
{
	printf("Hello, World!\n");
}

int main(int argc, char *argv[])
{
	fun1(fun2);
	return 0;
}
