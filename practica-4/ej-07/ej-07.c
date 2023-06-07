#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
Programar una función recursiva que reciba como parámetro un string conteniendo un
texto (ya cargado) y que retorne la cantidad de vocales que hay en éste. El prototipo de
la función debe ser:
unsigned int contar_vocales (char *);
*/


unsigned int contar_vocales(char*);

int main(int argc, char *argv[]) {
	
	char string[] = "Hola Buenos diAs";
	
	unsigned int numero_vocales = contar_vocales(string);
	
	printf("numero de vocales en el string: %d", numero_vocales);
	
	return 0;
}


unsigned int contar_vocales(char* string){
	unsigned int contador = 0;
	if(string!= NULL){
		if(*string == '\0'){
			return contador;
		}else if((*string == 'a' || *string == 'e' || *string == 'i' || *string == 'o' || *string == 'u') || (*string == 'A' || *string == 'E' || *string == 'I' || *string == 'O' || *string == 'U')){

			contador = 1 + contar_vocales(string+1);
		}else{
			contador = contar_vocales(string+1);

		}
	
		return contador;
	}
	
	
}

	
	
	
