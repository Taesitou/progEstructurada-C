#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Desarrollar una función que reciba como parámetros dos punteros a int y qué
intercambie los valores de las variables apuntadas por dichos punteros.
*/

void cambio(int* a, int* b ){
	int temp= *a;
	*a = *b;
	*b= temp;
}


int main(int argc, char *argv[]) {
	int a = 2;
	int b = 4;
	printf("Valores originales: a = %d, b= %d\n", a, b);
	cambio(&a, &b);
	printf("Valores intercambiados: a = %d, b= %d\n", a, b);
	return 0;
}

