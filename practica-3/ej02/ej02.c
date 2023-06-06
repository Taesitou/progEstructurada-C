#include <stdio.h>
#include <stdlib.h>

/*

Desarrollar una función que reciba como parámetro un arreglo de int y una posición de
dicho arreglo. Luego la función deberá retornar la dirección de memoria de la variable
que se encuentra en esa posición del arreglo.
Aclaración: La función se resuelve en una sóla línea de código.

*/


void direcMem(int arr[], int posicion ){
	printf("El numero: %d\nLa direccion: %p", arr[posicion], &arr[posicion]);	
}


int main(int argc, char *argv[]) {
	int arr[] = {1,2,3,4,5,6};
	direcMem(arr, 2);
	
	return 0;
}

