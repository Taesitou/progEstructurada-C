#include <stdio.h>
#include <stdlib.h>

/*
Desarrollar la función transponer?, que recibe por parámetro una matriz de int de
tamaño F x C (matriz cuadrada, F=C) y la modifique por su transpuesta.
Desarrollar el programa principal que cargue una matriz, luego la muestre en pantalla. A
continuación invocar a transponer y luego volver a imprimir para verificar su
transpuesta. Utilizar cargarMat, imprimirMat, desarrolladas anteriormente.
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
		

void transponer(int matriz[filas][columnas]){
	int f, c;
	for(f=0; f<filas; f++){
		for(c=f+1; c<columnas; c++){
			int remanente = matriz[f][c];
			matriz[f][c] = matriz[c][f];
			matriz[c][f] = remanente; // matriz [f][c]
			
			
		};
		
	}
	
}


int main() {
	int matriz[filas][columnas] = {0};
	cargarMat(matriz);
	imprimirMat(matriz);
	printf("\nTranspuesta:\n");
	transponer(matriz);
	imprimirMat(matriz);
	
	
	
	return 0;
}

