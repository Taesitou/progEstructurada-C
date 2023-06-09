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
	if(*nodo == NULL){
		*nodo = malloc(sizeof(struct s_nodo));
		(*nodo)-> producto = producto;
		(*nodo)->sig = NULL;
	}else{
		append(&((*nodo)->sig), producto);
	}
	
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
			producto.nombre= malloc(sizeof(char));
			letra = fgetc(arch);
			while(letra!= ','){
				producto.nombre[i] = letra;
				i++;
				producto.nombre = realloc(producto.nombre, sizeof(char) * (i+1));
				letra = fgetc(arch);
				
			}
			
			producto.nombre[i] = '\0';
			
			
			fscanf(arch, "%f,%d\n", &producto.precio, &producto.codigo);
			
			append(nodo, producto);
		}
		fclose(arch);
	}else{
		printf("No se pudo abrir");
	}
		
}

	
	
void imprimirRecursivo(t_nodo nodo){
	if(nodo !=NULL){
		printf("%20s | %14.2f | %14d\n", nodo->producto.nombre, nodo->producto.precio, nodo->producto.codigo);
		imprimirRecursivo(nodo->sig);
	}
}


int main(int argc, char *argv[]) {
	
	t_nodo lstProductos = NULL;
	
	cargarArch(&lstProductos);
	imprimirRecursivo(lstProductos);
	
	return 0;
}

