#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char* dameMemo(int cant){
	char* res = malloc(sizeof(char) * cant); // le doy 6 bytes // devuelve una direccion de memoria
	
	return res;
}
*/
typedef struct{
		int a,b;
		char* nom;
}t_punto;




char* dameMemo2(char** res, int cant){
	*res = malloc(sizeof(char) * cant); //mete un puntero en un puntero
	
	return res;
}

int main(int argc, char *argv[]) {
	/*
	char* arrC = NULL; // creamos arreglo dinamico
	//arrC = dameMemo(6); // le asigno memoria
	arrC = dameMemo2(arrC, 6)
	// en los ejemplos preguntar si hay memoria continua para asignar
	strcpy(arrC, "hola");
	printf("%s\n", arrC);
	*/
	
	t_punto* p=NULL;
	p= malloc(sizeof(t_punto)*1);
	(*p).a =  10;
	(*p).b = 20;
	damemMemo2(&((*p).nom),6);
	
	
	//*p.a=10; No se piede, contenido de null no se le puede asignar algo en un puntero
	
	
	
	return 0;
}

