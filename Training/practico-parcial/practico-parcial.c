#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct s_producto{
	char* nombre;
	float precio;
	int codigo;
};

typedef struct s_producto t_producto;


struct s_nodo{
	t_producto producto;
	struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

void append(t_nodo* nodo, t_producto producto){
	if(*nodo == NULL){ //si el puntero al nodo actual es NULL lo que indica que estamos en el final de la lista
		
		*nodo = malloc(sizeof(struct s_nodo)); // asignamos memoria al nodo
		(*nodo)->producto = producto; 		   // Asignamos datos del objeto producto al nuevo nodo
		(*nodo)->sig = NULL; 				   // sera el ultimo nodo de la lista
	}else{ 									   // si no es NULL hay todavia nodos en la lista
		append(&((*nodo)->sig), producto); 	   // pasamos al siguiente
	}
}
	
	
void ordenado_por_cod(t_nodo* nodo, t_producto producto){
	t_nodo aux = NULL; // nodo auxiliar 
	if(*nodo == NULL){
		*nodo = malloc(sizeof(struct s_nodo)); // asignamos memoria al nodo
		(*nodo)->producto = producto; 		   // Asignamos datos del objeto producto al nuevo nodo
		(*nodo)->sig = NULL; 				   // sera el ultimo nodo de la lista
	}else if(producto.codigo > (*nodo)->producto.codigo){ // si el codigo es mayir que el codigo del nodo, debemos insertar el nuevo antes del actual
		
		aux = malloc(sizeof(struct s_nodo)); // se asigna memoria al auxiliar
		aux->producto = producto; // se le asignan los datos del producto al nodo auxiliar
		aux->sig = *nodo; // se establece su puntero siguiente para apuntar al nodo actual
		*nodo = aux; // se actualiza el puntero al nodo inicial para que apunte al nuevo nodo auxiliar
		
		/*
		-tenemos que hacer una pila
		- asignar los datos del producto al auxiliar
		- su puntero siguiente apunta a nuestro nodo actual para ponerse primero
		- el nodo actual se convierte en el auxiliar
		*/
		
		
	}else{
		append(&((*nodo)->sig), producto);
	}
	
}

	
void ordenado_por_nom(t_nodo* nodo, t_producto producto){
	t_nodo aux = NULL; // nodo auxiliar 
	if(*nodo == NULL){
		*nodo = malloc(sizeof(struct s_nodo)); // asignamos memoria al nodo
		(*nodo)->producto = producto; 		   // Asignamos datos del objeto producto al nuevo nodo
		(*nodo)->sig = NULL; 				   // sera el ultimo nodo de la lista
	}else if(strcmp(producto.nombre, (*nodo)->producto.nombre) < 0){ // si el codigo es mayir que el codigo del nodo, debemos insertar el nuevo antes del actual
		
		aux = malloc(sizeof(struct s_nodo)); // se asigna memoria al auxiliar
		aux->producto = producto; // se le asignan los datos del producto al nodo auxiliar
		aux->sig = *nodo; // se establece su puntero siguiente para apuntar al nodo actual
		*nodo = aux; // se actualiza el puntero al nodo inicial para que apunte al nuevo nodo auxiliar
		
		/*
		-tenemos que hacer una pila
		- asignar los datos del producto al auxiliar
		- su puntero siguiente apunta a nuestro nodo actual para ponerse primero
		- el nodo actual se convierte en el auxiliar
		*/
		
	}else{
		append(&((*nodo)->sig), producto);
	}
}
	
void append_adelante(t_nodo* nodo, t_producto producto){
	t_nodo aux = NULL;
	if(*nodo == NULL){
		*nodo = malloc(sizeof(struct s_nodo));
		(*nodo)->producto= producto;
		(*nodo)->sig = NULL;
	}else{ // ya tiene nodo
		aux = malloc(sizeof(struct s_nodo));
		aux->producto= producto;
		aux->sig = *nodo; // sig apunta al nodo actual
		*nodo = aux;	  // el actual apunta al nuevo, convirtiendolo en el nuevo nodo inicial de la lista
	}
	
	// Lo mismo que los anteriores sin recursividad
	
}
	
	
	

		

void cargarArch(t_nodo* nodo){
	FILE* arch = fopen("datos.txt", "r");
	char titProd[20], titPre[20], titCod[20];
	char letra;
	t_producto producto;
	
	if(arch != NULL){
		
		fscanf(arch, "%[^,],%[^,],%[^\n]\n", titProd, titPre, titCod);
		
		printf("%20s | %14s | %14s\n", titProd, titPre, titCod);
		
		
		
		while(!feof(arch)){
			int i = 0;
			letra = fgetc(arch);
			producto.nombre = malloc(sizeof(char));
			while(letra != ','){
				producto.nombre[i] = letra;
				i++;
				producto.nombre = realloc(producto.nombre, sizeof(char) * (i+1));
				letra = fgetc(arch);
				
			}
			producto.nombre[i] = '\0';
			
			
			// precio y codigo;
			
			fscanf(arch, "%f,%d\n", &producto.precio, &producto.codigo);
			
			append(nodo, producto);
			//ordenado_por_cod(nodo, producto);
			//ordenado_por_nom(nodo, producto);
			//append_adelante(nodo, producto);
		}
		
		fclose(arch);
		
	}else{
		printf("No se pudo cargar el archivo");
	}
}


//    ## IMPRESIONES ##

// NORMAL
void imprimir(t_nodo lista){
	while(lista!=NULL){
		printf("%20s | %14.2f | %14d\n", lista->producto.nombre, lista->producto.precio, lista->producto.codigo);
		lista = lista->sig; // cambio lista para que siga en la proxima
	}
}

// RECURSIVOS
void imprimirRecursivo(t_nodo lista){
	if(lista != NULL){
		printf("%20s | %14.2f | %14d\n", lista->producto.nombre, lista->producto.precio, lista->producto.codigo);
		imprimirRecursivo(lista->sig);
	}
}
	
// RECURSIVO AL REVe
void imprimirRecursivoReverso(t_nodo lista){
	if(lista != NULL){
		imprimirRecursivoReverso(lista->sig); // llega hasta el final y empieza del final hacia el principio
		printf("%20s | %14.2f | %14d\n", lista->producto.nombre, lista->producto.precio, lista->producto.codigo);
	}
}
	
	
//	#### ELIMINACIONES #####

int main(int argc, char *argv[]) {
	t_nodo lstProductos = NULL;
	
	cargarArch(&lstProductos);
	
	//imprimir(lstProductos);
	//imprimirRecursivo(lstProductos);
	imprimirRecursivoReverso(lstProductos);
		
	return 0;
}

