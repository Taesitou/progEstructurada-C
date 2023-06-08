#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct s_titulo{
	char titProd[100];
	char titPre[100];
	char titCod[100];
};

typedef struct s_titulo cabecera;

struct s_producto{
	char* nombre;
	float precio;
	int codigo;
	struct s_producto* sig;
};


typedef struct s_producto producto;

void append(producto* lstProducto, char* nombre, float precio, int codigo){
	if(*lstProducto == NULL){
		lstProducto = (producto*)malloc(sizeof(producto)*1);
		
		(*lstProducto)->nombre = malloc(strlen(nombre)+sizeof(char)); //+1 para el char nulo
		strcpy((*lstProducto)->nombre, nombre);
		
		(*lstProducto)->precio = precio;
		(*lstProducto)->codigo = codigo;
		(*lstProducto)->sig = NULL;
		
	}else{
		append(&((*lstProducto)->sig), nombre, precio, codigo);
	}
	
}



void cargarArch(producto* lstProducto){
	FILE* arch = fopen("datos.txt", "r");
	
	cabecera titulares;
	
	lstProducto = (producto*)malloc(sizeof(producto)*1);
	
	if(arch != NULL){
		fscanf(arch,"%[^,],%[^,],%[^,\n]\n", titulares.titProd, titulares.titPre, titulares.titCod);
		printf("%s,%s,%s\n",titulares.titProd, titulares.titPre, titulares.titCod);
		
		
		int i = 0;
		
		while(fscanf(arch, "%[^,],%f,%d", lstProducto->nombre, &lstProducto->precio, &lstProducto->codigo) != EOF){
			append(&lstProducto, lstProducto->nombre, lstProducto->precio, lstProducto->codigo );
			printf("%10s,%.2f,%d", lstProducto->nombre, lstProducto->precio, lstProducto->codigo);
		}
		
	}else{
		printf("No se pudo cargar el archivo master\n");
	}
	
}




int main(int argc, char *argv[]) {
	producto* lstProducto = NULL;
	
	cargarArch(lstProducto);
	return 0;
}

