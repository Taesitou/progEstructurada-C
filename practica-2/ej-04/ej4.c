#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

typedef struct{
	char nombre[30];
	char pais[30];
	int documento;
} persona;

typedef struct{
	char nombre[30];
	char pais[30];
	int documento;
} listado;

void escribir(char archivo[20], persona humano[4]){
	FILE*arch= fopen(archivo, "w"); // w sobreescribe, a pone en el final
	int documento = 0;
	int i = 0, j = 0;
	int condicional;
	char caracter;
	
	if(arch == NULL){
		printf("No se pudo abrir el archivo");
	}else{
		/*
		int i, j;
		for(i=0; i<10; i++){
			for(j=0;j<20;j++){
				fputs("O ", arch);
				// fprintf(arch, "%d  ", j)
			}
			fputc('\n', arch);
		}
		printf("Escribe el documento");
	
		*/
		
		// pido documento del tipo
		while(j<2){
		condicional = 0;
		while(condicional == 0){
			printf("Escriba el numero de documento: ");
			scanf("%d", &documento);
			if(documento < 99999999 && documento > 0){
				fprintf(arch,"%d,", documento);
				condicional = 1;
				
			}else{
				printf("Error, Ingrese un numero de documento valido\n");
			}
			
		}
		
		getchar();		
		condicional = 0;
		// pido nombre del muchacho
		
		printf("Escribe el Nombre del tipo: ");
		while(i < 30 && condicional == 0){
			caracter = getchar();
			if(caracter != '\n'){
				
				humano[j].nombre[i] = caracter;
				i++;
				
			}else{
				caracter = '\0';
				humano[j].nombre[i] = caracter;
				fprintf(arch, "%s,",humano[j].nombre);
				condicional = 1;
			}
		}

		// reinicio variables
		
		condicional = 0;
		i = 0;
		// pido el pais
		printf("Escribe el pais del tipo: ");
		while(i < 30 &&  condicional == 0){
			caracter = getchar();
			if(caracter != '\n'){
				humano[j].pais[i] = caracter;
				i++;
				
			}else{
				caracter = '\0';
				humano[j].pais[i] = caracter;
				fprintf(arch, "%s\n",humano[j].pais);
				condicional = 1;
			}
		}
		i=0;
		j++;
		}
		
	}
	fflush(arch);
	fclose(arch);
}

	

// Ejercicio 5 
void verTabla(char archivo[20]){
	FILE*arch= fopen(archivo, "r");
	char caracter;
	char documento[20] = "Documento";
	char nombre[20] = "Nombre";
	char pais[20] = "Pais";
	int dni;
	char name[N];
	char country[N];
	int i = 0;
	
	if(arch == NULL){
		printf("No se pudo abrir el archivo");
	}else{
		printf("%s%15s%15s", documento, nombre, pais);
		printf("\n=========================================\n");
		while(fscanf(arch,"%d,%[^,],%[^,\n]", &dni, name,country) != EOF && i<2){
			
			printf("%d%18s%18s\n", dni, name, country);
			i++;
		} 
	}
}
	
void verTablaList(listado personas[4]){
	int i = 0;
	char documento[20] = "Documento";
	char nombre[20] = "Nombre";
	char pais[20] = "Pais";
	printf("%s%15s%15s", documento, nombre, pais);
	printf("\n=========================================\n");
	while(i<2){
		printf("%d%18s%18s\n", personas[i].documento, personas[i].nombre, personas[i].pais);
		i++;
	} 
}

	
// ejercicio 6
	
void verListado(char archivo[20]){
	
	FILE*arch = fopen(archivo, "r");
	
	listado personas[4];
	int opcion;
	int i=0, j;
	int tempDni;
	char tempNombre[N];
	char tempPais[N];
	
	
	printf("1- Ver listado ordenado por nombre\n");
	printf("2- Ver listado ordenado por documento\n");
	printf("3- Ver listado ordenado por país\n");
	printf("4- Salir del programa\n");
	scanf("%d", &opcion);
		
	// relleno listado de personas para despues comparar
	while((fscanf(arch,"%d,%[^,],%[^,\n]", &personas[i].documento, personas[i].nombre, personas[i].pais) != EOF) && i < 5){
		//printf("%d%18s%18s\n", personas[i].documento, personas[i].nombre, personas[i].pais);
		i++;
	} 
	
	
	if(opcion == 1){
		for(j=0; j<1; j++){
			if(strcmp(personas[j].nombre,personas[j+1].nombre) > 0 ){
				tempDni = personas[j].documento;
				personas[j].documento = personas[j+1].documento;
				personas[j+1].documento = tempDni;
				
				strcpy(tempNombre, personas[j].nombre);
				strcpy(personas[j].nombre,personas[j+1].nombre);
				strcpy(personas[j+1].nombre, tempNombre);
				
				strcpy(tempPais, personas[j].pais);
				strcpy(personas[j].pais,personas[j+1].pais);
				strcpy(personas[j+1].pais, tempPais);
			}
		}
		printf("Lista ordenada por Nombre:\n");
		verTablaList(personas);
		
	}else if(opcion == 2){
		for(j=0;j<1;j++){
			if(personas[j].documento < personas[j+1].documento){
				tempDni = personas[j].documento;
				personas[j].documento = personas[j+1].documento;
				personas[j+1].documento = tempDni;
				
				strcpy(tempNombre, personas[j].nombre);
				strcpy(personas[j].nombre,personas[j+1].nombre);
				strcpy(personas[j+1].nombre, tempNombre);
				
				strcpy(tempPais, personas[j].pais);
				strcpy(personas[j].pais,personas[j+1].pais);
				strcpy(personas[j+1].pais, tempPais);
			}
		}
		printf("Lista ordenada por Documento:\n");
		verTablaList(personas);
	}else if(opcion == 3){
		for(j=0; j<1; j++){
			if(strcmp(personas[j].pais,personas[j+1].pais) > 0 ){
				tempDni = personas[j].documento;
				personas[j].documento = personas[j+1].documento;
				personas[j+1].documento = tempDni;
				
				strcpy(tempNombre, personas[j].nombre);
				strcpy(personas[j].nombre,personas[j+1].nombre);
				strcpy(personas[j+1].nombre, tempNombre);
				
				strcpy(tempPais, personas[j].pais);
				strcpy(personas[j].pais,personas[j+1].pais);
				strcpy(personas[j+1].pais, tempPais);
			}
		}
		printf("Lista ordenada por Pais:\n");
		verTablaList(personas);
	}else{
		printf("Gracias por usar nuestro programa :)");
	}
	
	
	
}
	

	

int main() {
	char archivo[20] = "personas.txt";
	persona humano[4];
	escribir(archivo, humano);
	//verTabla(archivo);
	verListado(archivo);
	
	
	return 0;
}

