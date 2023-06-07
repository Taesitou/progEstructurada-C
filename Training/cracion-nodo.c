#include <stdio.h>
#include <stdlib.h>
/*
El ultimo nodo apunta a NULL
*/

typedef struct Nodo{
	char *nombre;
	int edad;
	struct Nodo *sig;
} Node;


Node *Iniciar(Node *Lista){
	Lista = NULL;
}

Node *Add(Node *Lista, char *string, int n ){
	Node *nuevo_nodo, *tmp;
	nuevo_nodo = (Node *)malloc(sizeof(Node));
	if(nuevo_nodo != NULL){ // para controlar que se cree
		nuevo_nodo -> nombre = string; // para acceder a los elementos del struct
		nuevo_nodo -> edad = n;
		nuevo_nodo -> sig = NULL;
		
		if(Lista == NULL){
			Lista = nuevo_nodo;
		}else{
			//Agregar el nodo alfinal de la lista
			
			tmp = Lista; // tmp == primer Nodo
			while(tmp->sig != NULL){ // para pararnos en el ultimo elemento, no en el NULL
				tmp = tmp->sig;
			}
			tmp->sig = nuevo_nodo;
			
			//Agregar de primero 
			/*
			nuevo_nodo->sig = Lista; // siguiente apunta al primero (el nuevo nodo apunta al siguiente de la lista)
			Lista = nuevo_nodo;
			 */
		}
	}else{
		puts("Memoria Llena");
			
	}
	
	return Lista;
}

	
void Print(Node *Lista){ // lo pasamos por valor no por referencia
	while(Lista != NULL){ // no estariamos escribiendo el ultimo elemento, si lo queremos ahacer asi seria con Lista != NULL 
		printf("Nombre: %s Lista: %p y Lista->sig: %p\n",Lista->nombre, Lista, Lista->sig);
		Lista = Lista->sig;
		
	}
}
int main(int argc, char *argv[]) {
	Node *Lista = Iniciar(Lista);
	Lista = Add(Lista, "Brayan", 19);
	Lista = Add(Lista, "Gabriela", 22);
	Print(Lista); 
	return 0;
}

