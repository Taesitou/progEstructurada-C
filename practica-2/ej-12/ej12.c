#include <stdio.h>

char letraMayus(char letra){
	return letra = letra ^ 32;
}

int main(int argc, char *argv[]) {
	char letra = 'a';
	printf("%c", letraMayus(letra));
	
	return 0;
}

