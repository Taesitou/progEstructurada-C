#include <stdio.h>
#include <stdlib.h>

/*

Desarrollar una funci�n que reciba como par�metro un arreglo de int y una posici�n de
dicho arreglo. Luego la funci�n deber� retornar la direcci�n de memoria de la variable
que se encuentra en esa posici�n del arreglo.
Aclaraci�n: La funci�n se resuelve en una s�la l�nea de c�digo.

*/


void direcMem(int arr[], int posicion ){
	printf("El numero: %d\nLa direccion: %p", arr[posicion], &arr[posicion]);	
}


int main(int argc, char *argv[]) {
	int arr[] = {1,2,3,4,5,6};
	direcMem(arr, 2);
	
	return 0;
}

