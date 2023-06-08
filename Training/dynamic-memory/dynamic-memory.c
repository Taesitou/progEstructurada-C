#include <stdio.h>
#include <stdlib.h>
/*

Vamos a poder reservar memoria en tiempo de ejecucion y liberarla tambien en tiempo de ejecucion

¿Necesito memoria? -> La pido cuando la necesito

¿Ya no necesito mas ese lugar de memoria?-> Lo libero y no ocupo recursos 

-Se labura con punteros y direcciones de memoria


malloc(): Nos servira para pedir memoria al sistema memory allocation(asignacion de memoria )

realloc(): reasignar memoria, por si me quede sin espacio

calloc(): reservar memoria para arreglos, vectores 

sizeof(): Nos va a decir cuanto tamaño en BYTES ocupa un tipo de dato

free(): Libera la memoria que hayamos reservado



punteros -> siempre 4 bytes

int -> 4 bytes
char -> 1 byte
double -> 8 bytes

*/


typedef struct{
	int x,y;
}tCoord;




int main(int argc, char *argv[]) {
	/*int *a, *b;
	
	a = (int *)malloc(sizeof(int));   // retorna un puntero, hay que casterlo con (int *) para que se cambie
	b = (int *)malloc(sizeof(int)); 
	
	*a = 5;
	*b = 10;
	
	printf("El valor de a es: %d", *a);
	printf("\nEl valor de b es: %d", *b);
	
	printf("\nEl valor de la suma entre a y b es : %d", (*a + *b));
	
	free(a); a=NULL; //recibe un puntero asi que lo pongo a secas 
	free(b); b=NULL;
	*/
	/* No elimina el valor qu etiene asignado esa variable, van a seguir almacenando en su variable, la direccion de mamoria que se le asigno con el malloc
	 lo que puede dar problemas a futuro, porque a y b van a seguir teniendo las direcciones de memoria que ya no le pertenecen 
	  por lo que si por equivocacion quiero acceder a lo que tiene a y guardar algo en esa variable o direccion, no es correcto y puede dar problemas
	 porque es una direccion de memoria que ya no le pertenece al programa, por lo cual usamos el NULL */
	
	
		/*
	tCoord *punto;
	
	punto = (tCoord *)malloc(sizeof(tCoord));
	
	printf("Ingrese x: "); scanf("%d", &punto->x); // tengo la direcciion de memoria, accedo por referencia al campo x, una vez que tengo eso el & aplica
	printf("Ingrese y: "); scanf("%d", &punto->y);
	
	printf("Valor de x: %d, valor de y: %d", punto->x, punto->y); // printf sin & ya, no como en scanf OBVIOUS 
	
	free(punto); punto = NULL; 
	*/
	
	
	// RESERVAR MEMORIA PARA UN vector
	
	int i, n, *lis;
	printf("Ingrese el tamaño de la lista: "); scanf("%d", &n);
	
	lis = (int *)malloc(sizeof(int)*n); // calloc(n, sizeof(int));
	
	for(i=0; i<n; i++){
		printf("\nIngrese el dato %d: ", i); 
		scanf("%d", &lis[i]);
	}
	
	for(i=0; i<n; i++){
		printf("\nEl dato %d: %d ", i, lis[i]); 
	}
	
	free(lis); lis=NULL;
	
	
	
	
	
	
	
	//printf("Tamaño en bytes: %d", sizeof(int *));
	
	
	
	return 0;
}

