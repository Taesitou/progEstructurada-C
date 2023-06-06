#include <stdio.h>
#include <stdlib.h>


/*
Crear una función recursiva que invierta un arreglo unidimensional dinámico de enteros
tal que su prototipo sea:
void invertir (int *, unsigned int);
Los parámetros de la función serán el arreglo a invertir y la cantidad de valores que hay
en el mismo.
Ejemplo:
valores originales: 6,2,7,1,8 
invertir(a, 5);
El arreglo a ahora contiene: 8, 1, 7, 2, 6 
*/

void invertir(int * , unsigned int );

int* crearArreglo(int n){
	int* arreglo;
	
	// asigno memoria al arreglo
	arreglo= (int*)malloc(n*sizeof(int));
	
	if(arreglo==NULL){
		printf("Error al asignar memoria");
		return NULL;
	}
	
	return arreglo;
}
	
	
void cargarArreglo(int* arreglo, int n){
	int i;
	
	for(i=0; i <= n; i++){
		if(i!=n){
			printf("Ingrese el elemento %d: ", i); scanf("%d", &arreglo[i]);
			
		}else{
			arreglo[i] = 0;
		}
	}
}
	
void imprimirArreglo(int* arreglo, int n){
	int i;
	printf("Arreglo: ");
	
	for(i=0; i<=n;i++){
		if(i!=n){
			printf("%d, ", arreglo[i]);
		}else{
			printf("%d", arreglo[i]);
		}
	}
}




int main(int argc, char *argv[]) {
	int i, n;
	int* arreglo;
	printf("Ingrese el tamaño del arreglo: "); scanf("%d", &n);
	
	arreglo = crearArreglo(n);
	
	cargarArreglo(arreglo, n);
		
	imprimirArreglo(arreglo, n);
	invertir(arreglo, n);
	imprimirArreglo(arreglo, n);
	
	return 0;
}


void invertir(int* arreglo, unsigned int n){
	
	if(n > 1){ // cuando esta en 0 o 1 ya esta invertido
		int auxiliar = *arreglo;
		//int cocacola = *(arreglo + n-1);
		*arreglo = *(arreglo + n-1);
		*(arreglo + n-1) = auxiliar;
		arreglo++;
		invertir(arreglo, n-2);
	}
	
	
}	
	


