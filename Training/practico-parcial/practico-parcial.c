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

void eliminar_cod(t_nodo* nodo, int codigo){ // puntero al puntero del nodo inicial
	//  para poder modificar el puntero al nodo original 
	// pasas la direccion de memoria, osea el original, no una copia
	t_nodo aux = NULL;
	if(*nodo != NULL){
		if((*nodo)->producto.codigo != codigo){
				eliminar_cod(&((*nodo)->sig), codigo);
		}else{
			aux = (*nodo);  // se crea un puntero auxiliar y se asigna el puntero al nodo actual;
			*nodo = (*nodo)->sig; // el puntero al nodo inicial empieza a apuntar al siguiente nodo
								  // esto para omitir el nodo actual de la lista
			free(aux); // se libera la memoria ocupada por el nodo eliminado 
			// eliminar_cod(&((*nodo)), codigo); // para ocurrencias
			
			/*
			creamos un auxiliar del nodo actual para despues eliminarlo
			el nodo actual apunta al siguiente
			eliminamos el auxiliar
			
			esto es para no perder la referencia al otro nodo
			mas facil
			auxiliar se convierte en elnodo
			el nodo pasa a ser el siguiente
			el auxiliar se borra
			*/
			
		}
	}
	
}
	
	
void eliminar_nom(t_nodo* nodo, char* nombre){
	t_nodo aux = NULL; // no le asignamos memoria ya que el uso es facilitar la eliminacion, no almacenar nuevos datos
	// lo usamos para mantener temporalmente la referencia al nodo actual que se eliminara de la lista
	// no necesita memory ya que auxiliar apuntaa al nodo existente, no se crea uno nuevo
	if(*nodo != NULL){
		if(strcmp((*nodo)->producto.nombre, nombre) != 0){
			eliminar_nom(&((*nodo)->sig), nombre);
		}else{
			aux = *nodo;
			*nodo = (*nodo)->sig;
			free(aux);
		}
	}
}


void eliminar_rango(t_nodo* nodo,  float inf, float sup){
	t_nodo aux = NULL;
	if(*nodo !=NULL){
		if((*nodo)->producto.precio >= inf && (*nodo)->producto.precio <= sup){
			aux = *nodo;
			*nodo = (*nodo)->sig;
			free(aux);
			eliminar_rango(&(*nodo), inf, sup); // para toda ocurrencia
		}else{
			eliminar_rango(&((*nodo)->sig), inf, sup);
		}
	}
	
}
	
//  #### BUSQUEDAS #######

void buscarCodigo(t_nodo* nodo, t_nodo lstFiltrada, int codigo ){
	if(*nodo != NULL){
		if((*nodo)->producto.codigo == codigo){ // el nodo actual coincide con el codigo?
			append(&lstFiltrada, (*nodo)->producto); // si coincide meter el producto en la nueva lista
		}
		buscarCodigo(&((*nodo)->sig), lstFiltrada, codigo); // sino coincide seguir
	}else{
		printf("###### Lista Filtrada ##########\n");
		imprimirRecursivo(lstFiltrada);
		
	}
}
	
	
	
void buscarNombre(t_nodo* nodo, t_nodo lstFiltrada, char* nombre){
	if(*nodo != NULL){
		if(strcmp((*nodo)->producto.nombre, nombre) == 0){
			append(&lstFiltrada, (*nodo)->producto);
		}
		buscarNombre(&((*nodo)->sig), lstFiltrada, nombre );
	}else{
		printf("###### Lista Filtrada ##########\n");
		imprimirRecursivo(lstFiltrada);
	}
}
	
	
void buscarRango(t_nodo* nodo, t_nodo lstFiltrada, float inf, float sup){
	if(*nodo != NULL){
		if((*nodo)->producto.precio >= inf && (*nodo)->producto.precio <= sup){
			append(&lstFiltrada, (*nodo)->producto);
		}
		buscarRango(&((*nodo)->sig), lstFiltrada, inf, sup);
	}else{
		printf("###### Lista Filtrada ##########\n");
		imprimirRecursivo(lstFiltrada);
	}
}
	
	
int esVocal(char* string){
	if(*string != '\0'){
		int Vocal = ((*string ==  'a' || *string ==  'e' || *string ==  'i' || *string == 'o' || *string ==  'u')||(*string ==  'A' || *string ==  'E' || *string ==  'I' || *string ==  'O' || *string ==  'U' ));
		return Vocal + esVocal(string+1) ;
	}
	
}
	

void buscarVocal(t_nodo* nodo, t_nodo lstFiltrada){
	if(*nodo != NULL){
		if(esVocal((*nodo)->producto.nombre) == 4){
			append(&lstFiltrada, (*nodo)->producto );
			
		}
		buscarVocal(&((*nodo)->sig), lstFiltrada);
	}
	else{
		printf("###### Lista Filtrada ##########\n");
		imprimirRecursivo(lstFiltrada);		
	}
}


int main(int argc, char *argv[]) {
	t_nodo lstProductos = NULL;
	t_nodo lstFiltrada = NULL;
	cargarArch(&lstProductos);
	
	//imprimir(lstProductos);
	imprimirRecursivo(lstProductos);
	//imprimirRecursivoReverso(lstProductos);
	
	printf("-----------------\n");
	
	
	//eliminar_cod(&lstProductos, 1821);
	//eliminar_nom(&lstProductos, "Goma Tinta");
	//eliminar_rango(&lstProductos, 7, 10);
	
	//buscarCodigo(&lstProductos, lstFiltrada, 1821);
	//buscarNombre(&lstProductos, lstFiltrada, "Goma Tinta");
	//buscarRango(&lstProductos, lstFiltrada, 7, 10);
	buscarVocal(&lstProductos, lstFiltrada);
	//imprimirRecursivo(lstFiltrada);
		
	return 0;
}

