#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct s_nodo{
	char* nombre;
	char* apellido;
	int dni;
	struct s_nodo* sig;
	
};

typedef struct s_nodo* t_nodo;

void append(t_nodo* nodo, char* nombre, char* apellido, int dni){
	if(*nodo == NULL){
		*nodo = malloc(sizeof(struct s_nodo));
		(*nodo)->nombre = malloc(strlen(nombre)+sizeof(char)); //+1 para el char nulo
		strcpy((*nodo)->nombre, nombre);
		(*nodo)->apellido = malloc(strlen(apellido)+sizeof(char)); // no *apellido = .. ya que es solo un puntero, no una variable que pueda almacenar un valor en si misma
		strcpy((*nodo)->apellido, apellido);
		(*nodo)->dni = dni;
		(*nodo)->sig = NULL;
		
	}else{
		append(&((*nodo)->sig), nombre, apellido, dni);
	}
	
	
}


	
void imprimirListRecursivo(t_nodo lista){
	if(lista != NULL){
		printf("nombre=%s, apellido=%s, dni=%d, dirNodo:<%p>, dirSig:<%p>\n", (lista)->nombre, (lista)->apellido, (lista)->dni, lista, lista->sig);
		imprimirListRecursivo(lista->sig);
	}
}
	

void imprimirListRecursivoInverso(t_nodo lista){
	if(lista != NULL){
		imprimirListRecursivo(lista->sig);
		printf("nombre=%s, apellido=%s, dni=%d, dirNodo:<%p>, dirSig:<%p>\n", (lista)->nombre, (lista)->apellido, (lista)->dni, lista, lista->sig);
		}
	
}




int main(int argc, char *argv[]) {
	t_nodo lista= NULL;
	
	append(&lista,"Tomas","Espinosa", 14);
	append(&lista,"Pablo","Abdala", 17);
	append(&lista,"Mateo","De la font", 20);
	append(&lista,"Gianni","guiso", 23);
	imprimirListRecursivo(lista);
	printf("-----------\n");
	imprimirListRecursivoInverso(lista);
	return 0;
}

