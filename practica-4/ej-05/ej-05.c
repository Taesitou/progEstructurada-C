#include <stdio.h>
#include <stdlib.h>

/*
Ej. 5:
a) Programar una funci�n recursiva que retorne el valor m�ximo de un arreglo
unidimensional din�mico de n�meros de enteros. El 0 (cero) marca el final de los valores �tiles
del arreglo.
b) Programar una funci�n recursiva que retorne la direcci�n de memoria del valor
m�ximo de un arreglo unidimensional din�mico n�meros de enteros. El 0 (cero) marca el final
de los valores �tiles del arreglo.
*/

int* crearArreglo(int n){
	int* arreglo;
	
	// asigno memoria para el arreglo
	arreglo = (int*)malloc(n* sizeof(int));
	
	if(arreglo == NULL){
		printf("Error al asignar memoria");
		return NULL;
	}
	
	return arreglo;
}


void cargarArreglo(int* arreglo, int n){
	int i;
	
	for(i= 0; i <= n; i++){
		if(i!=n){
			printf("Ingrese el elemento %d: ", i); scanf("%d", &arreglo[i]);
		}else{
			arreglo[i] = 0;
		}
	}
}


void imprimirArreglo(int* arreglo, int n){
	int i;
	//imprimo arreglo
	printf("Arreglo: ");
	for(i = 0; i <= n; i++){
		if(i != n){
			printf("%d, ", arreglo[i]);
		}else{
			printf("%d ", arreglo[i]);
		}
	}
		
}
	
	
	/*a) Programar una funci�n recursiva que retorne el valor m�ximo de un arreglo
		unidimensional din�mico de n�meros de enteros. El 0 (cero) marca el final de los valores �tiles
		del arreglo.*/
int valorMax(int* arreglo){
	int mR;
	int maximo = *arreglo;
	if(*arreglo != 0){ // caso base
		arreglo++;
		mR = valorMax(arreglo);
		if(mR>maximo && *arreglo!= 0){
			maximo = mR;
		}
	}
	
	return maximo;
	
}
	
	
	/*b) Programar una funci�n recursiva que retorne la direcci�n de memoria del valor
		m�ximo de un arreglo unidimensional din�mico n�meros de enteros. El 0 (cero) marca el final
		de los valores �tiles del arreglo.*/
	
int* dirValorMax(int *arreglo){
	int* mR = NULL;
	int* maximo = NULL;
	maximo = arreglo;
	if(*arreglo != 0){ // caso base
		arreglo++;
		mR = dirValorMax(arreglo);
		if((*mR)>(*maximo) && *arreglo!= 0){
			maximo = mR;
		}
	}
	
	return maximo;
}

int main(int argc, char *argv[]) {
	int i, n;
	int* arreglo;
	printf("Ingrese el tama�o del arreglo: "); scanf("%d", &n);
	
	arreglo = crearArreglo(n);
	
	cargarArreglo(arreglo, n);
	
	imprimirArreglo(arreglo, n);
	int dir = valorMax(arreglo);
	
	printf("\nEl valor maximo del array es: %d",valorMax(arreglo));
	printf("\nLa direccion del valor maximo del array es: %p, %p",dirValorMax(arreglo), &dir);
	
	free(arreglo);
	
	
	
	return 0;
}

