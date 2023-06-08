#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ej 3 en la practica
/*
Ej. 3: Hacer una función que elimina un nodo de una lista de enteros. La función recibirá como
parámetros una lista (la dirección del puntero al primer elemento de la lista) y el valor
que contiene el nodo a ser eliminado. Si el valor estuviera repetido, se eliminará el
primer nodo que lo contenga. Considere que la lista puede estar vacía o que el valor
solicitado no se encuentre.
	3.1. Hacer un eliminar todas las ocurrencias.
	3.2. Ahora el contenido es una estructura EJ: nombre, apellido y DNI. Realizar
		el ejercicio utilizando dicha estructura.
		3.2.1. eliminar una ocurrencias
		3.2.2. eliminar todas las ocurrencias
		3.2.3. eliminar por DNI, eliminar por apellido, eliminar por nombre.
*/
/*
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
	
	append(&lista,"Tomas","mariposa", 14);
	append(&lista,"Pablo","Abeja", 2);
	append(&lista,"Mateo","De la font", 12);
	append(&lista,"Gianni","guiso", 3);
	imprimirListRecursivo(lista);
	printf("-----------\n");
	
	return 0;
}

*/

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
	}else{
		append(&((*nodo)->sig), val);
	}
}
/*
void eliminar(t_nodo* nodo, int valor){
	t_nodo aux = NULL;
	if(*nodo != NULL){
		if((*nodo)->val == valor){
			aux = (*nodo); // a lo que apunta nodo (lo que queremos eliminar)
			*nodo = (*nodo)->sig; // nodo pasa a apuntar al proximo nodo del que queriamos eliminar
			free(aux);
			
		}else{
			eliminar(&((*nodo)->sig), valor);
		}
	}
}
	*/
	
	

// ocurrencia
void eliminar(t_nodo* nodo, int valor){
	t_nodo aux = NULL;
	if(*nodo != NULL){
		if((*nodo)->val == valor){
			aux = (*nodo); // a lo que apunta nodo (lo que queremos eliminar)
			*nodo = (*nodo)->sig; // nodo pasa a apuntar al proximo nodo del que queriamos eliminar
			free(aux);
			eliminar(&(*nodo), valor); // no pasa al siguiente ya que sino se va el apuntdor
		}else{
			eliminar(&((*nodo)->sig), valor);
		}
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
	append(&lista, 2);
	append(&lista, 12);
	append(&lista, 2);
	imprimirListRecursivo(lista);
	printf("-----------\n");
	eliminar(&lista, 2);
	imprimirListRecursivo(lista);
	return 0;
}


