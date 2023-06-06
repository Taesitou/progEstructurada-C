#include <stdio.h>
#include <stdlib.h>
/*
Programar una funci�n recursiva que ordene en forma creciente un arreglo din�mico
unidimensional de n�meros enteros. El 0 (cero) marca el final de los valores �tiles del
arreglo. Utilizar (dentro de la funci�n a desarrollar) la funci�n recursiva programada
anteriormente para determinar la posici�n de memoria del valor m�nimo del arreglo.
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
	
/*

	Programar una funci�n recursiva que ordene en forma creciente un arreglo din�mico
	unidimensional de n�meros enteros. 
	*/
int valorMin(int* arreglo){
	int mR;
	int minimo = *arreglo;
	if(*arreglo != 0){ // caso base
		arreglo++;
		mR = valorMin(arreglo);
		if(mR<minimo && *arreglo!= 0){
			minimo = mR;
		}
	}
	
	return minimo;
	
}
	
void intercambiar(int*a, int*b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;	
}
void ordenarArr(int *arreglo, int n){
	
	
	int i;
	if(n!=1){
		for(i=0; i < n-1; i++){
			if(arreglo[i] > arreglo[i+1]){
				intercambiar(&arreglo[i], &arreglo[i+1]);
			}
		}
		
		ordenarArr(arreglo, n-1);
	}else{
		return;
	}
}
	


int main(int argc, char *argv[]) {
	
	int n;
	int* arreglo;
	
	printf("Ingrese el tama�o del arreglo: "); scanf("%d", &n);
	
	arreglo = crearArreglo(n);
	cargarArreglo(arreglo, n);
	imprimirArreglo(arreglo, n);
	
	printf("\nEl valor minimo del array es: %d",valorMin(arreglo));
	
	printf("\nEl array ordenado es: ");
	
	ordenarArr(arreglo, n);
	imprimirArreglo(arreglo, n);
	
	return 0;
}

