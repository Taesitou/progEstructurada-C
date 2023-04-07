#include <stdio.h>
#include <stdlib.h>
/*
Desarrollar las funciones cargarMat?, imprimirMat?, y promMat?.
	cargarMat?: carga desde teclado una matriz de int de tamaño F x C pasada por
	parámetro. La matriz se debe cargar completa.
	imprimirMat?: imprime en pantalla el contenido una matriz de int de F x C pasada por
	parámetro.
	promMat?: recibe por parámetro una matriz de int de tamaño F x C y retorna un número
	real que representa el promedio de los valores de la matriz.
	Desarrollar el programa principal que invocando a las funciones mencionadas, cargue
	una matriz, imprima la matriz e imprima el promedio de los valores de la matriz.
	*/

#define filas 3
#define columnas 3

void cargarMat(int matriz[filas][columnas]){
	
	int f, c;
	int numero;
	for(f=0; f<filas; f++){
		for(c=0; c<columnas; c++){
			printf("coloque el numero deseado en la posicion [%d][%d]: ", f, c);
			scanf("%d", &numero);
			matriz[f][c] = numero;
		}
		printf("\n");
	}
	
	
}

void imprimirMat(int matriz[filas][columnas]){
	int f, c;
	for (f=0; f<filas; f++){
		printf("[");
		for(c=0; c<columnas; c++){
			if(c == columnas-1){
				printf("%d", matriz[f][c]);
			}else{
				printf("%d, ", matriz[f][c]);
			}
			
		}
		printf("]\n");
	}
	
	
}

double promMat(int matriz[filas][columnas]){
	int suma = 0;
	int f, c;
	int divisor = filas * columnas;
	for(f=0; f<filas; f++){
		for(c=0; c<columnas; c++){
			suma += matriz[f][c]; 
			
		}
	}
	return suma/divisor;
}



int main() {
	int matriz[filas][columnas] = {0};
	cargarMat(matriz);
	imprimirMat(matriz);
	printf("%f", promMat(matriz));
	return 0;
}

