#include <stdio.h>
/*
Realizar una función que muestre la representación binaria de una variable de tipo char,
utilizando los operadores SHIFT (desplazamiento a izquierda y a derecha). Aplicarla en
un programa de ejemplo.

para poner un cierto bit en 1 cen unavariable, lo que haremos es hacer un OR | binario con una mask que
tenga ese bit en 1

para saber ti una variable tiene cierto bit en 1 lo que hacemos es un AND binario & 
con una mask que tenga ese bit en 1

se puede alteral el contenido de un bit (cambiar 1 por 0 o al reves) con XOR ^  con una mascara que
tenga dicho bit en 1. Si en la posicion habia un 1 se va a 0. si habia 0, se va a 1.

*/


/*
Uso n for para recorrer los 8 bits de caracter,
empezando por el 7 y terminando en el 0. usamos >> para mover el bit actual
a la pos menos signidicativa(0) y los & para obtener el valor del bit actual



a = 		0 1 1 0 0 0 0 1


>>7         0 0 0 0 0 0 0 0  & 0 0 0 0 0 0 1  = 0 0 0 0 0 0 0 0
>>6         0 0 0 0 0 0 0 1  & 0 0 0 0 0 0 1  = 0 0 0 0 0 0 0 1
>>5         0 0 0 0 0 0 1 1  & 0 0 0 0 0 0 1  = 0 0 0 0 0 0 1 1
>>4         0 0 0 0 0 1 1 0  & 0 0 0 0 0 0 1  = 0 0 0 0 0 1 1 0 
>>3         0 0 0 0 1 1 0 0  & 0 0 0 0 0 0 1  = 0 0 0 0 1 1 0 0 
>>2         0 0 0 1 1 0 0 0  & 0 0 0 0 0 0 1  = 0 0 0 1 1 0 0 0
>>1         0 0 1 1 0 0 0 0  & 0 0 0 0 0 0 1  = 0 0 1 1 0 0 0 0
>>0         0 1 1 0 0 0 0 1  & 0 0 0 0 0 0 1  = 0 1 1 0 0 0 0 1 = a
*/

void binario(char caracter){
	int i;
	int mask = 1;
	for(i = 7; i>= 0; i--){
		printf("%d", (caracter>>i) & mask);
	}
	printf("\n");
}


int main(int argc, char *argv[]) {
		unsigned char c = 'a';
		printf("La letra '%c' en binario es: ", c);
		binario(c);
	return 0;
}

