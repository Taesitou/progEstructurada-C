#include <stdio.h>



void leer(char texto[101]){
	int i = 0;
	char aux;
	printf("Ingresar Texto: ");
	char term = '\n';
	aux = getchar();
	
	while(aux!=term && i<101){
		texto[i] = aux;
		i++;
		if(i< 101){
			aux = getchar();
		}
	}
	texto[i] = '\0';
	//printf("%s", texto);
}

void reemplazar(char texto[101], char letraVieja, char letraNueva){
	int i;
	for(i = 0; i < 101; i++){
		if(texto[i] == letraVieja){
			texto[i] = letraNueva;
		}
		
	}
}


int main() {
	char texto[101] = {0};
	leer(texto);
	char letraVieja, letraNueva;
	
	printf("Letra a reemplazar en el texto: ");
	letraVieja = getchar();
	getchar();
	
	printf("Letra a reemplazada en el texto: ");
	letraNueva = getchar();
	getchar();
	
	reemplazar(texto, letraVieja, letraNueva);
	
	printf("\nResultado: %s", texto);
		
	
	
	
	return 0;
}

