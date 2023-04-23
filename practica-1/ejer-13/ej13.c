#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define filas 9
#define columnas 20

void cargarMat(char matriz[filas][columnas], char archivo[20]){
	int f=0,c=0;
	int caracter;
	FILE*arch = fopen(archivo, "r");
	
	if( arch == NULL){
		printf("No se pudo abrir el archivo :(");
	}else{
		while((caracter = fgetc(arch)) !=EOF){
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
	
	
	

void cargarMatNum(int matriz[filas][columnas], char archivo2[20]){
	FILE*arch2 = fopen(archivo2, "r");
	int aux;
	
	if(arch2 == NULL){
		printf("No se pudo abrir el archivo :(");
	}else{
		int fil = 0, col=0;
		int pts, pj, pg, pe, pp, gf, gc, dif;
		do{
			aux = fscanf(arch2,"%d,%d,%d,%d,%d,%d,%d,%d", &pts, &pj, &pg, &pe, &pp, &gf, &gc, &dif);
			int list[8]= {pts, pj, pg, pe, pp, gf, gc, dif};
			while(col<8){
				matriz[fil][col] = list[col];
				col++;
			}
			col=0;
			fil++;
		}while(aux!= EOF && fil < 5);
			
		
	}
	fclose(arch2);
	
}
	
void imprimirMatNum(int matriz[filas][columnas]){
	int f, c;
	for(f=0;f<5;f++){
		printf("[");
		for(c=0;c<8;c++){
			if(c==7 && matriz[f][c] >0){
				printf("%+5d", matriz[f][c]);
			}else{
				printf("%5d", matriz[f][c]);
			}
		}
		printf("]\n");
	}
}
	
	
void imprimirMatText(char matriz[filas][columnas]){
	int f, c;
	for(f=0;f<filas;f++){
		printf("[");
		for(c=0;c<columnas-1 && matriz[f][c] != '\0' ;c++){
			printf("%c", matriz[f][c]);
		}
		printf("]\n");
	}
}
	
	
	
// ejers
void ordenarTabla(char matrizItems[filas][columnas], int matrizDatos[filas][columnas], int numColumna,int numero){ // esta funcion debe ordenar segun la columna elegida :)
	
	int f, c;
	
	int temp;
	char tempStr[25];
	if(numero == 1){
		for(f=0;f<5;f++){
			for(c=0;c<8;c++){
				if(c == numColumna){
					int j=0;
					while(j<5){
						if (matrizDatos[j][c]<matrizDatos[j+1][c]){
							for(int k = 0; k<8; k++){
								
								// las filas
								temp = matrizDatos[j][k];
								matrizDatos[j][k] = matrizDatos[j+1][k];
								matrizDatos[j+1][k] = temp;
							}
							//los strings
							strcpy(tempStr, matrizItems[j]); // destino, origen
							strcpy(matrizItems[j], matrizItems[j+1]);
							strcpy(matrizItems[j+1], tempStr);
						}	
						j++;
					}
				}
			}
		}
	}else if(numero == 0){
		for(f=0;f<4;f++){ // se reduce a 4 ya que se comparara con el siguiente (en caso de no hacer eso, me dara como resultado una fila con todo 0000)
			for(c=0;c<8;c++){
				if(c == numColumna){
					int j=0;
					while(j<4){
						if (matrizDatos[j][c]>matrizDatos[j+1][c]){
							for(int k = 0; k<8; k++){
								
								
								// las filas
								temp = matrizDatos[j][k];
								matrizDatos[j][k] = matrizDatos[j+1][k];
								matrizDatos[j+1][k] = temp;
							}
							//los strings
							strcpy(tempStr, matrizItems[j]); // destino, origen
							strcpy(matrizItems[j], matrizItems[j+1]);
							strcpy(matrizItems[j+1], tempStr);
						}	
						j++;
					}
				}
			}
		}
		
	}
	
	
}
	
	


void imprimirTabla(char matrizCabecera[filas][columnas], char matrizItems[filas][columnas], int matrizDatos[filas][columnas]){
	int f,c;
	
	// cabecera
	for(f=0;f<filas;f++){
		if(f==0){
		for(c=0;c<15;c++){
			printf("%c", matrizCabecera[f][c]);
		}
		}else{
			for(c=0;c<5;c++){
				printf("%c", matrizCabecera[f][c]);
			}
		}
	}
	printf("\n-----------------------------------------------------\n");
	// equipos con respectivo puntaje
	for(f=0;f<5;f++){
		printf("%-13s", matrizItems[f]);
		for(c=0;c<8;c++){
			if(c == 7 && matrizDatos[f][7] > 0){
				printf("%+5d", matrizDatos[f][c]);
			}
			else{
				printf("%5d", matrizDatos[f][c]);
			}
			
			
		}
		printf("\n");
	}
}

int main() {
	
	
	char matrizCabecera[filas][columnas] = {0};
	char matrizItems[filas][columnas] = {0};
	int matrizDatos[filas][columnas] = {0};
	
	char archivo[20] = "cabeceras.txt";
	char archivo1[20] = "items.txt";
	char archivo2[20] = "datos.txt";
	
	cargarMat(matrizCabecera, archivo);
	cargarMat(matrizItems, archivo1);
	imprimirMatText(matrizCabecera);
	printf("\n");
	imprimirMatText(matrizItems);
	printf("\n");
	cargarMatNum(matrizDatos, archivo2);
	imprimirMatNum(matrizDatos);
	
	printf("\n");
	printf("\n");
	printf("TABLA ORIGINAL");
	printf("\n");
	printf("\n");
	
	imprimirTabla(matrizCabecera,matrizItems,matrizDatos);
	
	printf("\n");
	printf("\nTABLA MODIFIED\n");
	printf("\n");
	ordenarTabla(matrizItems,matrizDatos,0,1);
	imprimirTabla(matrizCabecera,matrizItems,matrizDatos);
	

	
	
	
	return 0;
}

