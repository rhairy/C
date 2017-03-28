test: demo.o alg.o
	gcc demo.o alg.o -o test
demo.o: demo.c
	gcc -c demo.c -o demo.o
alg.o: alg.c alg.h
	gcc -c alg.c -o alg.o