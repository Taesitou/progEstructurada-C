#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// tipo de estructura de datos como char
typedef struct{
	char nombre[30];
	char autor[30];
	int publicacion;
	int edicion;
	float precio;
} libro;

int main(int argc, char *argv[]) {
	int i;
	libro LB[3];
	for(i=0;i<2;i++){
		printf("Ingrese el nombre del libro: ");
		fgets(LB[i].nombre,30,stdin);
		printf("Ingrese el nombre del autor: ");
		fgets(LB[i].autor,30,stdin);
		printf("Ingrese el año de publicacion: ");
		scanf("%i", &LB[i].publicacion);
		printf("Ingrese el numero de edicion: ");
		scanf("%i", &LB[i].edicion);
		printf("Ingrese el precio del libro: ");
		scanf("%f", &LB[i].precio);
		fflush(stdin);
	}
	
	system("pause");
	system("cls");

	for(i=0;i<2;i++){
		printf("El nombre del libro %i es: %s. \n", i+1, LB[i].nombre);
		printf("El autor del libro es: %s. \n", LB[i].autor);
		printf("La publicacion es del año:  %i. \n",LB[i].publicacion);
		printf("La edicion del libro es : %i. \n",LB[i].edicion);
		printf("El precio del libro es: %.2f.\n", LB[i].precio);
		
	}
	
	system("pause");
	
	return 0;
}

