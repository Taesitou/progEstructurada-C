#include <stdio.h>
#include <stdlib.h>
#define TAMMAX 100


/*
Las pills nos pueden servir para saber si todos los parentiesis que se abrieron
en una cierta expresion, fueron cerrados
ej ((a+b)+c)
Es una lista

*/


typedef struct{
	int lis[TAMMAX];
	int tam; // tamaño que tambien sirve para saber en que posicicon se encuentra el ult elemento de la lista
}tPila;


tPila inicializaPila(){
	tPila pila;
	pila.tam = 0;
	
	return pila;
}
	

int estaVacia(tPila pila){
	return pila.tam == 0; // true or false
}
int estaLlena(tPila pila){
	return pila.tam == TAMMAX - 1; // -1 porque empieza en 0
}
	
	
	
void push(tPila *pila, int elem){
	// mete elemento en la ultima posicion n+1
	if (!estaLlena(*pila)){
		pila->tam = pila->tam+1;
		pila->lis[pila->tam] = elem;
	}else{
		printf("Pila Llena\n");
	}
	
}
int pop(tPila *pila){
	int elem;
	if(!estaVacia(*pila)){
		elem = pila->lis[pila->tam];
		pila->tam = pila->tam-1;
		return elem;
	}else{
		printf("Pila Vacia\n");
		return -1;
	}
}


int main(int argc, char *argv[]) {
	
	tPila pila;
	int elem;
	
	pila = inicializaPila();
	push(&pila, 10);
	push(&pila, 13);
	push(&pila, 12);
	
	while(!estaVacia(pila)){
		elem = pop(&pila);
		printf("Elemento eliminado: %d\n", elem);
	}
	
	
	return 0;
}

