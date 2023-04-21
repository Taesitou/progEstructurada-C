#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define filas 5
#define columnas 20





// cargar en la matriz los nombres de los equipos del texto 

void cargarMatTexDeArch(char matriz[filas][columnas],char archivo[20]){
	int f, c; 
	FILE*arch;
	//char term = '\n';
	int caracter;
	arch = fopen(archivo,"r");
	
	if(arch == NULL){
		printf("No se pudo abrir el archivo");
	}else{
		f= 0;
		c=0;
		while((caracter = fgetc(arch))!= EOF && f<filas){
			// best way
			
			if(caracter == '\n'){
				c=0;
				f++;
			}else{
				matriz[f][c] = caracter;
				c++;
			}
			
			
			/*
			matriz[f][c] = caracter; 
			//printf("%c",matriz[f][c]);
			if(c < columnas-1){
				c++;
			}else{
				c= 0;
				f++;
			}
			*/
		}
	}
}

void imprimirMatText(char matriz[filas][columnas]){
	int f, c;
	for (f=0; f<filas; f++){
		printf("[");
		for(c=0; c<columnas-1 ; c++){
			printf("%c", matriz[f][c]);
		}
		printf("]\n");
	}
}

	
// shift - tab

int main() {
	char matriz[filas][columnas] = {0};
	char archivo[20]="equipos.txt";
	cargarMatTexDeArch(matriz, archivo);
	imprimirMatText(matriz);
	
	return 0;
}

