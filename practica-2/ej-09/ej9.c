#include <stdio.h>

void desplazar_y_completar(char c, int posiciones) {
	c = c >> posiciones;
	int i;
	for (i = 7; i >= 0; i--) {
		printf("%d", (c >> i) & 1);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	unsigned char c = 'a';
	unsigned int posiciones = 3;
	printf("La letra '%c' desplazada %d posiciones en binario es: ", c, posiciones);
	desplazar_y_completar(c, posiciones);
	
	return 0;
}
	
