#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct s_producto{
	char* nombre;
	float precio;
	int codigo;
};

typedef struct s_producto producto;

struct s_nodo{
	producto producto;
	struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;


//     #### CARGAS ####
void append(t_nodo* nodo, producto producto){
	if(*nodo == NULL){
		
		*nodo = malloc(sizeof(struct s_nodo));
		(*nodo)->producto = producto;
		(*nodo)->sig = NULL;
		
	}else{
		append(&((*nodo)->sig), producto);
	}
	
}

void ordenado_por_cod(t_nodo* nodo, producto producto){
	t_nodo aux = NULL;
	if(*nodo == NULL){ //inserto Ultimo
		*nodo = malloc(sizeof(struct s_nodo));
		(*nodo)->producto = producto;
		(*nodo)->sig = NULL;
		
	}else if(producto.codigo > (*nodo)->producto.codigo){
		aux = malloc(sizeof(struct s_nodo));
		aux->producto = producto;
		aux->sig = *nodo;
		*nodo = aux;
		
	}else{
		ordenado_por_cod(&((*nodo)->sig), producto);
		
	}

}


	
void ordenado_por_nom(t_nodo* nodo, producto producto){
	t_nodo aux = NULL;
	if(*nodo == NULL){ //inserto Ultimo
		*nodo = malloc(sizeof(struct s_nodo));
		(*nodo)->producto = producto;
		(*nodo)->sig = NULL;
		
	}else if(strcmp(producto.nombre, (*nodo)->producto.nombre) < 0){
		aux = malloc(sizeof(struct s_nodo));
		aux->producto = producto;
		aux->sig = *nodo;
		*nodo = aux;
		
	}else{
		ordenado_por_cod(&((*nodo)->sig), producto);
	}
}
		
	
void append_adelante(t_nodo* nodo, producto producto){
	t_nodo aux = NULL;
	if(*nodo == NULL){ //inserto Ultimo
		*nodo = malloc(sizeof(struct s_nodo));
		(*nodo)->producto = producto;
		(*nodo)->sig = NULL;
		
	}else{
		aux = malloc(sizeof(struct s_nodo));
		aux->producto = producto;
		aux->sig = *nodo;
		*nodo = aux;
	}	
}			

	
void cargarArch(t_nodo* nodo){
		FILE* arch = fopen("datos.txt", "r");
		char titProd[20], titPre[20], titCod[20];
		
		producto producto;
		char letra;
		
		if(arch != NULL){
			fscanf(arch,"%[^,],%[^,],%[^\n]\n", titProd, titPre, titCod);
			printf("%20s | %14s | %14s\n", titProd, titPre, titCod);
			
			while(!feof(arch)){
				int i = 0;
				
				letra = fgetc(arch);
				producto.nombre =  malloc(sizeof(char));
				
				while(letra != ','){
					producto.nombre[i] = letra;
					i++;
					producto.nombre = realloc(producto.nombre, sizeof(char) * (i+1));
					letra = fgetc(arch);
				}
				
				producto.nombre[i] = '\0';
				
				// PRECIO Y CODIGO
				fscanf(arch, "%f,%d\n", &producto.precio, &producto.codigo);
				
				//append_adelante(nodo, producto);
				//ordenado_por_nom(nodo, producto);
				//ordenado_por_cod(nodo, producto);
				append(nodo, producto);
			}
			
			free(producto.nombre);
			fclose(arch);
			
			
		}else{
			printf("No se pudo cargar el archivo master\n");
		}
		
		
	}
// -----------------------
	
	
//     ####	IMPRESIONES ####


//ITERATIVO
void imprimirListaDer(t_nodo lista){
	while(lista != NULL){
		printf("%20s | %14.2f | %14d\n", lista->producto.nombre, lista->producto.precio, lista->producto.codigo);
		lista = lista->sig;
	}
}
	
// RECURSIVOS
void imprimirListaRecursivo(t_nodo lista){
	if(lista != NULL){
		printf("%20s | %14.2f | %14d\n", lista->producto.nombre, lista->producto.precio, lista->producto.codigo);
		imprimirListaRecursivo(lista->sig);
	}
}

void imprimirListaRecursivoInv(t_nodo lista){
	if(lista != NULL){
		imprimirListaRecursivoInv(lista->sig);
		printf("%20s | %14.2f | %14d\n", lista->producto.nombre, lista->producto.precio, lista->producto.codigo);
		
	}
}
	
// ###########	Eliminaciones ##########

void eliminar_cod(t_nodo* nodo, int codigo){
	t_nodo aux = NULL;
	if(*nodo != NULL){
		if((*nodo)->producto.codigo != codigo){
			eliminar_cod(&(*nodo)->sig, codigo);
			
		}else{
			aux = (*nodo);
			*nodo = (*nodo)->sig;
			free(aux);
			//eliminar(&(*nodo), codigo);  para ocurrencia
		}
	}
}

	
void eliminar_nom(t_nodo* nodo, char* nombre){
	t_nodo aux = NULL;
	if(*nodo != NULL){
		if(strcmp((*nodo)->producto.nombre, nombre) != 0){ // == 0 son iguales
			eliminar_nom(&(*nodo)->sig, nombre);
			
		}else{
			aux = (*nodo);
			*nodo = (*nodo)->sig;
			free(aux);
			//eliminar(&(*nodo), nombre); para ocurrencia
		}
	}
}
	

void eliminar_rango(t_nodo* nodo, int inf, int sup){
	t_nodo aux = NULL;
	if(*nodo != NULL){
		if(((*nodo)->producto.precio >= inf) && ((*nodo)->producto.precio <= sup) ){ // == 0 son iguales
			aux = (*nodo);
			*nodo = (*nodo)->sig;
			free(aux);
			
			eliminar_rango(&(*nodo), inf, sup); // para ocurrencias
			
		}else{
			eliminar_rango(&(*nodo)->sig, inf, sup);
			
		}
	}
}
	
	
// ########## 	Busquedas ################
	
void buscarCodigo(t_nodo* lista, t_nodo listaFiltrada, int codigo){
	
	if(*lista != NULL){
		if((*lista)->producto.codigo == codigo){
			append(&listaFiltrada, (*lista)->producto);
		}
		buscarCodigo(&((*lista)->sig),listaFiltrada, codigo);
	}else{
		printf(" ###### Lista Filtrada ######\n");
		imprimirListaRecursivo(listaFiltrada);
	}
	
}
	
void buscarNombre(t_nodo* lista, t_nodo listaFiltrada, char* nombre){
	if(*lista != NULL){
		if(strcmp((*lista)->producto.nombre,nombre) == 0){
			append(&listaFiltrada, (*lista)->producto);
		}
		buscarNombre(&((*lista)->sig), listaFiltrada, nombre);
	}else{
		printf(" ###### Lista Filtrada ######\n");
		imprimirListaRecursivo(listaFiltrada);
	}
	
	
	
}
	
	
// ## ejer vocales by Pablo ##
	
int esVocal(char* string){
	if(*string!= '\0'){
		int vocal = ((*string == 'a' || *string == 'e' || *string == 'i' || *string == 'o' || *string == 'u') || (*string == 'A' || *string == 'E' || *string == 'I' || *string == 'O' || *string == 'U'));
		return vocal + esVocal(string+1);
	}
}

	
void buscarVocales(t_nodo* lista, t_nodo listaFiltrada ){
	if(*lista != NULL){
		if(esVocal((*lista)->producto.nombre) == 4){
			append(&listaFiltrada, (*lista)->producto);
		}
		buscarVocales(&((*lista)->sig), listaFiltrada);
	}else{
		printf(" ###### Lista Filtrada ######\n");
		imprimirListaRecursivo(listaFiltrada);
	}
}
	
	
	
void buscarRango(t_nodo* lista, t_nodo listaFiltrada,  int inf, int sup){

	if(*lista != NULL){
		if(((*lista)->producto.precio >= inf) && ((*lista)->producto.precio <= sup)){
			append(&listaFiltrada, (*lista)->producto);
		}
		buscarRango(&((*lista)->sig), listaFiltrada, inf, sup);
	}else{
		printf(" ###### Lista Filtrada ######\n");
		imprimirListaRecursivo(listaFiltrada);
	}
}	
	
// ejers by Taesito
void buscarMayorPrecio(t_nodo* lista, t_nodo listaFiltrada){
	static float mayor = 0;
	t_nodo auxiliar = NULL;
	if(*lista != NULL){
		if((*lista)->sig == NULL){
			append(&listaFiltrada, auxiliar->producto);
		}else if((*lista)->producto.precio > mayor){
			auxiliar = (*lista);
			mayor = (*lista)->producto.precio;
		}
		buscarMayorPrecio(&((*lista)->sig), listaFiltrada);
	}else{
		printf(" ###### Lista Filtrada ######\n");
		imprimirListaRecursivo(listaFiltrada);
	}
}


int main(int argc, char *argv[]) {
	t_nodo lstProducto = NULL;
	t_nodo lstFiltrada = NULL;
	
	cargarArch(&lstProducto);
	
	//imprimirListaDer(lstProducto, cabecera);
	imprimirListaRecursivo(lstProducto);
	//imprimirListaRecursivoInv(lstProducto);
	printf("---------------\n");
	
	//eliminar_cod(&lstProducto, 1821);
	//eliminar_nom(&lstProducto, "lapicera Bic");
	//eliminar_rango(&lstProducto, 7, 12 );
	//imprimirListaRecursivo(lstProducto);
	
	//buscarCodigo(&lstProducto, lstFiltrada ,1821);
	//buscarNombre(&lstProducto, lstFiltrada, "papel glace");
	//buscarRango(&lstProducto, lstFiltrada, 7, 12);
	//buscarVocales(&lstProducto, lstFiltrada);
	buscarMayorPrecio(&lstProducto, lstFiltrada);
	//imprimirListaRecursivo(listaFilRango);
	
	
	
	return 0;
}

