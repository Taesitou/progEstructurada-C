#include <stdio.h>

int cantidad(int numero){
	int i;
	int mask = 1;
	int contador = 0;
	for(i=7;i>=0; i--){
		if(((numero>>i)& mask) == 1){
			contador++;
		}
	}
	return contador;
}


int main() {
	unsigned int numero = 9;
	printf("La cantidad de bits que estan en 1 en el numero '%d' son: %d", numero, cantidad(numero));
	return 0;
}

