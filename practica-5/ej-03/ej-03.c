#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Ej. 2: Realizar una función que inserte un valor entero en una lista de enteros ordenada,
preservando el orden.
2.1. Ahora el contenido es una estructura EJ: nombre, apellido y DNI. Realizar
el ejercicio utilizando dicha estructura. Hacer tres insertar ordenado:

*/
/*
struct s_nodo{
	int val;
	struct s_nodo* sig;
};

typedef struct s_nodo* t_nodo;



void append(t_nodo* nodo, int val){
	if( *nodo == NULL){
		*nodo = malloc(sizeof(struct s_nodo));
		(*nodo)->val = val;
		(*nodo)->sig = NULL;
	}else if(val < (*nodo)->val){
		int temp = (*nodo)->val;
		(*nodo)->val = val;
		append(&((*nodo)->sig), temp);
	}else{
		append(&((*nodo)->sig), val);
		
	}
}

void imprimirListRecursivo(t_nodo lista){
	if(lista != NULL){
		printf("valor=%d, dirNodo:<%p>, dirSig:<%p>\n", (lista)->val, lista, lista->sig);
		imprimirListRecursivo(lista->sig);
	}
}
	





int main(int argc, char *argv[]) {
	t_nodo lista= NULL;
	
	append(&lista, 14);
	append(&lista, 10);
	append(&lista, 12);
	append(&lista, 7);
	imprimirListRecursivo(lista);
	printf("-----------\n");
	
	return 0;
}
*/



/*
Ej. 2: Realizar una función que inserte un valor entero en una lista de enteros ordenada,
preservando el orden.
2.1. Ahora el contenido es una estructura EJ: nombre, apellido y DNI. Realizar
el ejercicio utilizando dicha estructura. Hacer tres insertar ordenado:
2.1.1. insertar ordenado por DNI.
2.1.2. insertar ordenado por apellido.
2.1.3. insertar ordenado con la posibilidad de pasar por parámetro el
número de campo por el cual se desea ordenar.
*/


struct s_nodo{
	char* nombre;
	char* apellido;
	int dni;
	struct s_nodo* sig;
	
};
typedef struct s_nodo* t_nodo;



/*//ordenado por Dni	
void append(t_nodo* nodo, char* nombre, char* apellido, int dni){
	if(*nodo == NULL){
		*nodo = malloc(sizeof(struct s_nodo));
		(*nodo)->nombre = malloc(strlen(nombre)+sizeof(char)); //+1 para el char nulo
		strcpy((*nodo)->nombre, nombre);
		
		(*nodo)->apellido = malloc(strlen(apellido)+sizeof(char)); // no *apellido = .. ya que es solo un puntero, no una variable que pueda almacenar un valor en si misma
		strcpy((*nodo)->apellido, apellido);
		
		(*nodo)->dni = dni;
		(*nodo)->sig = NULL;
		
	}else if(dni < (*nodo)->dni){
		int temp_dni = (*nodo)->dni;
		(*nodo)->dni = dni;
		
		char* temp_nombre = malloc(strlen((*nodo)->nombre) + sizeof(char));
		char* temp_apellido = malloc(strlen((*nodo)->apellido) + sizeof(char));
		
		
		strcpy(temp_nombre, (*nodo)->nombre);
		strcpy(temp_apellido, (*nodo)->apellido);
		
		strcpy((*nodo)->nombre, nombre);
		strcpy((*nodo)->apellido, apellido);
		
		append(&((*nodo)->sig), temp_nombre, temp_apellido, temp_dni);
		
	}else{
		append(&((*nodo)->sig), nombre, apellido, dni);
	}
}	
*/


//ordenado por apellido
/*
void append(t_nodo* nodo, char* nombre, char* apellido, int dni){
	if(*nodo == NULL){
		*nodo = malloc(sizeof(struct s_nodo));
		(*nodo)->nombre = malloc(strlen(nombre)+sizeof(char)); //+1 para el char nulo
		strcpy((*nodo)->nombre, nombre);
		(*nodo)->apellido = malloc(strlen(apellido)+sizeof(char)); // no *apellido = .. ya que es solo un puntero, no una variable que pueda almacenar un valor en si misma
		strcpy((*nodo)->apellido, apellido);
		(*nodo)->dni = dni;
		(*nodo)->sig = NULL;
		
	}else if(strcmp(apellido, (*nodo)->apellido) < 0){
		int temp_dni = (*nodo)->dni;
		(*nodo)->dni = dni;

		char* temp_nombre = malloc(strlen((*nodo)->nombre) + sizeof(char));
		char* temp_apellido = malloc(strlen((*nodo)->apellido) + sizeof(char));


		strcpy(temp_nombre, (*nodo)->nombre);
		strcpy(temp_apellido, (*nodo)->apellido);

		strcpy((*nodo)->nombre, nombre);
		strcpy((*nodo)->apellido, apellido);

		append(&((*nodo)->sig), temp_nombre, temp_apellido, temp_dni);
		
	}else{
		append(&((*nodo)->sig), nombre, apellido, dni);
	}
}	
*/

//ordenado como guste el don
void append(t_nodo* nodo, char* nombre, char* apellido, int dni, int n){
	
	
	
	
	if(*nodo == NULL){
		*nodo = malloc(sizeof(struct s_nodo));
		(*nodo)->nombre = malloc(strlen(nombre)+sizeof(char)); //+1 para el char nulo
		strcpy((*nodo)->nombre, nombre);
		(*nodo)->apellido = malloc(strlen(apellido)+sizeof(char)); // no *apellido = .. ya que es solo un puntero, no una variable que pueda almacenar un valor en si misma
		strcpy((*nodo)->apellido, apellido);
		(*nodo)->dni = dni;
		(*nodo)->sig = NULL;
		
	}else if( (n == 1) && (strcmp(nombre, (*nodo)->nombre) < 0)){
		int temp_dni = (*nodo)->dni;
		(*nodo)->dni = dni;
		
		char* temp_nombre = malloc(strlen((*nodo)->nombre) + sizeof(char));
		char* temp_apellido = malloc(strlen((*nodo)->apellido) + sizeof(char));
		
		
		strcpy(temp_nombre, (*nodo)->nombre);
		strcpy(temp_apellido, (*nodo)->apellido);
		
		strcpy((*nodo)->nombre, nombre);
		strcpy((*nodo)->apellido, apellido);
		
		append(&((*nodo)->sig), temp_nombre, temp_apellido, temp_dni, n);
		
	}else if( (n == 2) && (strcmp(apellido, (*nodo)->apellido) < 0)){
		int temp_dni = (*nodo)->dni;
		(*nodo)->dni = dni;
		
		char* temp_nombre = malloc(strlen((*nodo)->nombre) + sizeof(char));
		char* temp_apellido = malloc(strlen((*nodo)->apellido) + sizeof(char));
		
		
		strcpy(temp_nombre, (*nodo)->nombre);
		strcpy(temp_apellido, (*nodo)->apellido);
		
		strcpy((*nodo)->nombre, nombre);
		strcpy((*nodo)->apellido, apellido);
		
		append(&((*nodo)->sig), temp_nombre, temp_apellido, temp_dni, n);
		
	}else if( (n == 3) && (dni < (*nodo)->dni)){
		int temp_dni = (*nodo)->dni;
		(*nodo)->dni = dni;
		
		char* temp_nombre = malloc(strlen((*nodo)->nombre) + sizeof(char));
		char* temp_apellido = malloc(strlen((*nodo)->apellido) + sizeof(char));
		
		
		strcpy(temp_nombre, (*nodo)->nombre);
		strcpy(temp_apellido, (*nodo)->apellido);
		
		strcpy((*nodo)->nombre, nombre);
		strcpy((*nodo)->apellido, apellido);
		
		append(&((*nodo)->sig), temp_nombre, temp_apellido, temp_dni, n);
		
	}else{
		append(&((*nodo)->sig), nombre, apellido, dni, n);
	}
}	



void imprimirListRecursivo(t_nodo lista){
	if(lista != NULL){
		printf("nombre=%s, apellido=%s, dni=%d, dirNodo:<%p>, dirSig:<%p>\n", lista->nombre, lista->apellido, lista->dni, lista, lista->sig);
		imprimirListRecursivo(lista->sig);
	}
}






int main(int argc, char *argv[]) {
	t_nodo lista= NULL;
	
	int n;
	printf("Hable ahora o calle para siempre ¿Que prefiere? (calle siempre)\n");
	printf("1- Ordenar por nombre\n");
	printf("2- Ordenar por apellido\n");
	printf("3- Ordenar por dni\n");
	printf("Escriba su eleccion: "); scanf("%d", &n);
	
	append(&lista,"Tomas","Espinosa", 14, n);
	append(&lista,"Pablo","Abdala", 2, n);
	append(&lista,"Mateo","De la font", 12, n);
	append(&lista,"Gianni","guiso", 3, n);
	imprimirListRecursivo(lista);
	printf("-----------\n");

return 0;
}

