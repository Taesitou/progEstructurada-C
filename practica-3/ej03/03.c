#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*

Desarrollar una funci�n que redondee al entero m�s pr�ximo el valor contenido en una
variable externa de tipo double.
Aclaraci�n: La funci�n no deber� retornar valores.

*/


void redondear(double* valor){
	*valor = round(*valor);
	printf("El numero entero redondeado es %.0f", *valor);
	/*
	int entero = *valor;
	if((*valor-entero)> 0.5 ){
		*valor += (1-(*valor-entero));
		printf("El numero entero redondeado para arriba es: %p", valor);
	}else{
		printf("El numero entero redondeado para abajo es: %d", entero);
	}
	
	*/
}



int main(int argc, char *argv[]) {
	double numero = 2.31;
	redondear(&numero);
	
	return 0;
}

