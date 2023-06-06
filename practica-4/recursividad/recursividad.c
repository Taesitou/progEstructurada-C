#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
RECURSIVIDAD
una funcion que se llama asi misma
- Cada vez que llamas a una funcion, ocupa una nueva parte de la memoria
*/


/*



void funR(int cant){
	

	if(cant>0){
		printf("%d, %s\n",cant, "Hola");
		funR(cant-1);
		printf("%d, %s\n",cant, "Hola"); // queda el remanente, y empieza desde la ultima hasta la primera
	}else{
		printf("- -- - - - - - -\n");
	}

	
}*/

/*
int funR(int cant){
	
	if(cant<=0){	
		return 0;
	}else{
		return cant+funR(cant-1);
	}
}

*/



typedef struct{
	int x,y;
	char* nom;
	
}t_punto;





// hacer una funcion recursiva que devuelva como una multiplicacion ejemplo : 5*3 = 5+5+5
int funR(int a, int b){
	if(b!=1){
		return a+funR(a,b-1);
	}
	return 0;
}

int main(int argc, char *argv[]) {
		
	t_punto* p=NULL;
	p= malloc(sizeof(t_punto)*1);
	(*p).x=10;
	p->y=20;
	p->nom=malloc(sizeof(char)*7);
	strcpy(p->nom,"hola");
	printf("%d,%d,%s", p->x,p->y,p->nom);
	
	//printf("%d\n", funR(5,3));
	
	
	
	return 0;
}

