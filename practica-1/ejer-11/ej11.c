#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 25
#define filas 5
#define columnas 25





void cargarMatTexDeArch(char matriz[filas][columnas],char archivo[20]){
	int f, c; 
	FILE*arch;
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
				matriz[f][c] = '\0';
				c=0;
				f++;
				
			}else{
				matriz[f][c] = caracter;
				c++;
			}
			
		}
	}
	fclose(arch);
}
	
void imprimirMatText(char matriz[filas][columnas]){
	int f, c;
	for (f=0; f<filas; f++){
		printf("[");
		for(c=0; c<columnas-1 && matriz[f][c] != '\0'; c++){
			printf("%c", matriz[f][c]);
		}
		printf("]\n");
	}
}
	
void ordenarTexto(char matriz[filas][N]){
	int f,c;
	char temp[N];
	for(f=0;f<filas-1;f++){
		for(c=f+1;c<filas;c++){
			if(strcmp(matriz[f],matriz[c]) > 0){
				strcpy(temp, matriz[f]); // destino, origen
				strcpy(matriz[f], matriz[c]);
				strcpy(matriz[c], temp);
			}	
		}
		
	}
	
	}
	

	


int main() {
	char matriz[filas][columnas] = {0};
	char archivo[20]="equipos.txt";
	cargarMatTexDeArch(matriz, archivo);
	imprimirMatText(matriz);
	printf("-------------------\n");
	printf("%5s", "ORDENADA\n");
	ordenarTexto(matriz);
	
	imprimirMatText(matriz);
	return 0;
}

