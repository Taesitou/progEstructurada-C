#include <stdio.h>

struct s_carta{
	int numero, valor;
	char palo;
};
typedef struct s_carta t_carta;

/*
Dado el struct

Desarrollar una función que modifique el contenido de 3 variables externas de este tipo,
de manera que las cartas almacenadas en éstas queden ordenadas según su valor en el
juego del “Truco”.


*/

void ordenar(t_carta* carta1, t_carta* carta2, t_carta* carta3){
	t_carta aux;
	
	t_carta* cartas[3] = {carta1, carta2, carta3};
	int i, j;
	for(i=0;i<3;i++){
		for(j=i+1;j<3;j++){
			if (cartas[i]->valor > cartas[j]->valor){
				aux = *cartas[i];
				*cartas[i] = *cartas[j];
				*cartas[j] = aux;
			}
		}
	}


	
	
	
	
	
	
	
	
	
	
	
	
	printf("carta 1: %c\ncarta 2: %c\ncarta3: %c", carta1->palo, carta2->palo, carta3->palo);
	
	
	
}


int main(int argc, char *argv[]) {
	
	t_carta espada;
	espada.numero = 1;
	espada.palo = 'e';
	espada.valor = 1;
		
		
	t_carta basto;
	basto.numero = 1;
	basto.palo = 'b';
	basto.valor = 2;
		
		
	t_carta siete_espada;
	siete_espada.numero = 7;
	siete_espada.palo = 'e';
	siete_espada.valor = 3;
		
	ordenar(&basto, &siete_espada, &espada); // 2,3,1
	
	return 0;
}

