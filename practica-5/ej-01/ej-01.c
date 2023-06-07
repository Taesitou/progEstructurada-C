#include <stdio.h>
#include <stdlib.h>

/*
Ej. 1: Realizar una función recursiva que imprima el contenido de una lista de enteros
en forma inversa. Si la lista contiene 14,17,20,23, entonces el programa deberá
imprimir: 23, 20, 17, 14.
1.1. Ahora el contenido es una estructura EJ: nombre, apellido y DNI. Realizar
el ejercicio utilizando dicha estructura.
1.2. Inventar otra estructura más compleja y probar nuevamente.

*/

struct s_nodo{
	int val;
	struct s_nodo* sig;
};

typedef struct s_nodo* t_nodo;


void append(t_nodo* nodo, int val){
	if( *nodo == NULL){
		*nodo = malloc(sizeof(struct s_nodo));
		(*nodo)->val = val;
		(*nodo)->sig = NULL;
	}else{
		append(&((*nodo)->sig), val);
	}
}
	
void imprimirListRecursivo(t_nodo lista){
	if(lista != NULL){
		printf("valor=%d, dirNodo:<%p>, dirSig:<%p>\n", (lista)->val, lista, lista->sig);
		imprimirListRecursivo(lista->sig);
	}
}

void imprimirListRecursivoInverso(t_nodo lista){
	if(lista!= NULL){
		imprimirListRecursivoInverso(lista->sig);
		printf("valor=%d, dirNodo:<%p>, dirSig:<%p>\n", (lista)->val, lista, lista->sig);
	}
}

		
		
int main(int argc, char *argv[]) {
	t_nodo lista= NULL;
	
	append(&lista, 14);
	append(&lista, 17);
	append(&lista, 20);
	append(&lista, 23);
	imprimirListRecursivo(lista);
	printf("-----------\n");
	imprimirListRecursivoInverso(lista);
	return 0;
}
		

	
		
