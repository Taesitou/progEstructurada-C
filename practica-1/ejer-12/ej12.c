#include <stdio.h>
#include <stdlib.h>
#define filas 5
#define columnas 9


void cargarMatNumDeArch(int matriz[filas][columnas], char archivo[20]){
	FILE*arch;
	arch = fopen(archivo, "r");
	int num1, num2, num3, num4, num5, num6, num7, num8;
	int aux;
	int fil = 0; // sumara para si misma, like i j k
	if(arch == NULL){
		printf("No se pudo abrir el archivo");
	}else{ // no lee, (todo aquello que este en el segundo argumento que no sea un tipo de dato, lo evita)
		aux = fscanf(arch,"%d,%d,%d,%d,%d,%d,%d,%d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8);
		while(aux != EOF && fil<filas ){
			matriz[fil][0]= num1;
			matriz[fil][1]= num2;
			matriz[fil][2]= num3;
			matriz[fil][3]= num4;
			matriz[fil][4]= num5;
			matriz[fil][5]= num6;
			matriz[fil][6]= num7;
			matriz[fil][7]= num8;
			
			aux = fscanf(arch,"%d,%d,%d,%d,%d,%d,%d,%d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8);
			fil++;
		}
	}
}
	
void imprimirMatNum(int matriz[filas][columnas]){
	int f, c;
	for (f=0; f<filas; f++){
		printf("[");
		for(c=0; c<columnas-1 ; c++){
			if(c == 7 && matriz[f][c] > 0){
				printf("%+5d", matriz[f][c]);
				
			}else{
				printf("%5d", matriz[f][c]);
			}
			
		}
		printf("]\n");
	}
}
		

int main() {
	int matriz[filas][columnas] = {0};
	char archivo[20] = "puntos.txt";
	cargarMatNumDeArch(matriz, archivo);
	imprimirMatNum(matriz);
	return 0;
}

