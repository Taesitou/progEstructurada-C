#include <stdio.h>
#include <stdlib.h>
#define filas 3
#define columnas 20

void cargarMatText(char matriz[filas][columnas]){
	int f, c;
	char aux;
	char term = '\n';
	
	for(f=0; f<filas; f++){
		printf("Girame palabritas master: ");
		aux = getchar();
		for(c=0;c<columnas && aux != term;c++){
			matriz[f][c] = aux;
			aux = getchar();
			
			
		}
		matriz[f][c] = '\0';
	}
	
}

void imprimirMatText(char matriz[filas][columnas]){
	int f, c;
	for (f=0; f<filas; f++){
		printf("[");
		for(c=0; c<columnas; c++){
			if(matriz[f][c] == ' '){
				printf(","); // printeo una coma en lugar de un espacio      //  printf("%c,", matriz[f][c]);
			}else{
				printf("%c", matriz[f][c]);
			}
			
		}
		printf("]\n");
	}	
	
	
	
}
	
	

void ordenarMatText(char matriz[filas][columnas]){
	int f, c, i;
	char aux;
	for(f=0; f<filas-1; f++){
		
		for(c=0 ;c<filas-1;c++){
			if(matriz[f][0]>matriz[c+1][0]){
				for(i=0; i<columnas; i++){
					aux = matriz[c+1][i];
					matriz[c+1][i] = matriz[f][i];
					matriz[f][i] = aux;
				}
			}
		}
	}
	
	
}

			
			
			
			
int main() {
	
	char matriz[filas][columnas] = {0};
	cargarMatText(matriz);
	imprimirMatText(matriz);
	ordenarMatText(matriz);
	printf("Matriz ordenada: \n");
	imprimirMatText(matriz);
	
	
	return 0;
}


