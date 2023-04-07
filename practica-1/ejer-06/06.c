#include <stdio.h>
/*
void imprimirArr(char array[101]){
	int i;
	printf("Tu array es:  [");
	for( i = 0; array[i] != 0 && i < 101; i++){
		if (array[i+1] == 0 || i == 100){
			printf("%]\n", array[i]);
			
		}else{
			printf("%d, ", array[i]);
		}
	}
	
}
*/
void imprimirTexto(char texto[100]){
	printf("El texto ingresado es: ");
	for(int x = 0; texto[x] != '\0'; x++){
		printf("%c", texto[x]);
		
	}
}

void cargarText(char array[101]){
	char term = '\n';
	char aux;
	printf("Ingresar Texto: ");
	aux = getchar();
	
	int i = 0;
		
	while(aux != term && i < 101){
		array[i] = aux;
		i++;
		if(i<101){
			aux = getchar();
		}
	}
	array[i]= '\0';

}

void normalizar(char array[101]){
	
	if(array[0] >= 'a' && array[0]<= 'z'){
		array[0] = array[0]-32;
	}
	
	int j;
	
	for(int i = 0; array[i] != '\0'; i++ ){
		if(array[i] == ' ' && array[i+1] == ' ' ){
			for(j = i; array[j]!='\0'; j++){
				array[j+1] = array[j+2];
			}
		}
		if(array[i+1] == '\0'){
			array[i] = '.';
		}
	}
		
}

int main() {
	char array[101];
	cargarText(array);
	
	normalizar(array);
	imprimirTexto(array);
	
		
	return 0;
}

